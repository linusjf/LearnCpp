#include <arm_neon.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef float float8_t __attribute__((ext_vector_type(8)));

void step(float *r, const float *d, int n);
constexpr float infty = numeric_limits<float>::infinity();

constexpr float8_t f8infty{infty, infty, infty, infty,
                           infty, infty, infty, infty};

static float8_t *float8_alloc(size_t n) {
  void *tmp = 0;
  if (posix_memalign(&tmp, sizeof(float8_t), sizeof(float8_t) * n))
    throw bad_alloc();
  return (float8_t *)tmp;
}

static inline float hmin8(float8_t vv) {
  float v = infty;
  for (int i = 0; i < 8; ++i)
    v = min(vv[i], v);
  return v;
}

static inline float8_t min8(float8_t x, float8_t y) {
  float8_t z;
  for (int i = 0; i < 8; i++)
    z[i] = x[i] < y[i] ? x[i] : y[i];
  return z;
}

static inline float8_t swap4(float8_t x) {
  return _mm256_permute2f128_ps(x, x, 0b00000001);
}

static inline float8_t swap2(float8_t x) {
  return _mm256_permute_ps(x, 0b01001110);
}

static inline float8_t swap1(float8_t x) {
  return _mm256_permute_ps(x, 0b10110001);
}

float *generate_dists(int n) {
  float *d = (float *)new float[n * n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      *(d + i * n + j) = i == j ? 0.0f : (float)(rand() % 100 + 1);
  return d;
}

int main(int argc, char **argv) {
  constexpr int n = 1000;
  srand(time(NULL));
  const float *d = generate_dists(n);
  cout << "Generated" << endl;
  float r[n * n];
  clock_t start;
  double duration;
  start = clock();
  step(r, d, n);
  duration = (clock() - start) / (double)CLOCKS_PER_SEC;
  cout << "Stepped" << endl;
  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << r[i * n + j] << " ";
      if (j % 10 == 9)
        cout << endl;
    }
    cout << endl;
    cout << endl;
  }*/
  cout << "step: " << duration << " seconds" << endl;
  delete[] d;
}

void step(float* r, const float* d_, int n) {
    constexpr int cols_per_stripe = 500;
    int na = (n + 8 - 1) / 8;

    // Build a Z-order curve memory access pattern for vd and vt
    vector<tuple<int,int,int>> rows(na*na);
    #pragma omp parallel for
    for (int ia = 0; ia < na; ++ia) {
        for (int ja = 0; ja < na; ++ja) {
            int ija = _pdep_u32(ia, 0x55555555) | _pdep_u32(ja, 0xAAAAAAAA);
            rows[ia*na + ja] = make_tuple(ija, ia, ja);
        }
    }

    sort(rows.begin(), rows.end());

    // One stripe of rows and cols packed into float8_ts
    float8_t* vd = float8_alloc(na*cols_per_stripe);
    float8_t* vt = float8_alloc(na*cols_per_stripe);
    // Partial results
    float8_t* vr = float8_alloc(na*na*8);

    for (int stripe = 0; stripe < n; stripe += cols_per_stripe) {
        int stripe_end = min(n - stripe, cols_per_stripe);

        // Load one row and column stripe from d
        #pragma omp parallel for
        for (int ja = 0; ja < na; ++ja) {
            for (int id = 0; id < stripe_end; ++id) {
                int t = cols_per_stripe * ja + id;
                int i = stripe + id;
                for (int jb = 0; jb < 8; ++jb) {
                    int j = ja * 8 + jb;
                    vd[t][jb] = j < n ? d_[n*j + i] : infty;
                    vt[t][jb] = j < n ? d_[n*i + j] : infty;
                }
            }
        }

        #pragma omp parallel for
        for (int i = 0; i < na * na; ++i) {
            // Get corresponding pair (x, y) for Z-order value ija
            int ija, ia, ja;
            tie(ija, ia, ja) = rows[i];
            (void)ija;
            // If we are not at column 0, then the partial results contain something useful, else the partial results are uninitialized
            float8_t vv000 = stripe ? vr[8*i + 0] : f8infty;
            float8_t vv001 = stripe ? vr[8*i + 1] : f8infty;
            float8_t vv010 = stripe ? vr[8*i + 2] : f8infty;
            float8_t vv011 = stripe ? vr[8*i + 3] : f8infty;
            float8_t vv100 = stripe ? vr[8*i + 4] : f8infty;
            float8_t vv101 = stripe ? vr[8*i + 5] : f8infty;
            float8_t vv110 = stripe ? vr[8*i + 6] : f8infty;
            float8_t vv111 = stripe ? vr[8*i + 7] : f8infty;

            // Compute partial results for this column chunk
            for (int k = 0; k < stripe_end; ++k) {
                float8_t a000 = vd[cols_per_stripe*ia + k];
                float8_t b000 = vt[cols_per_stripe*ja + k];
                float8_t a100 = swap4(a000);
                float8_t a010 = swap2(a000);
                float8_t a110 = swap2(a100);
                float8_t b001 = swap1(b000);
                vv000 = min8(vv000, a000 + b000);
                vv001 = min8(vv001, a000 + b001);
                vv010 = min8(vv010, a010 + b000);
                vv011 = min8(vv011, a010 + b001);
                vv100 = min8(vv100, a100 + b000);
                vv101 = min8(vv101, a100 + b001);
                vv110 = min8(vv110, a110 + b000);
                vv111 = min8(vv111, a110 + b001);
            }
            vr[8*i + 0] = vv000;
            vr[8*i + 1] = vv001;
            vr[8*i + 2] = vv010;
            vr[8*i + 3] = vv011;
            vr[8*i + 4] = vv100;
            vr[8*i + 5] = vv101;
            vr[8*i + 6] = vv110;
            vr[8*i + 7] = vv111;
        }
    }

    // Unpack final results from partial results
    #pragma omp parallel for
    for (int i = 0; i < na * na; ++i) {
        int ija, ia, ja;
        tie(ija, ia, ja) = rows[i];
        (void)ija;
        float8_t vv[8];
        for (int kb = 0; kb < 8; ++kb) {
            vv[kb] = vr[8*i + kb];
        }
        for (int kb = 1; kb < 8; kb += 2) {
            vv[kb] = swap1(vv[kb]);
        }
        for (int jb = 0; jb < 8; ++jb) {
            for (int ib = 0; ib < 8; ++ib) {
                int i = ib + ia*8;
                int j = jb + ja*8;
                if (j < n && i < n) {
                    r[n*i + j] = vv[ib^jb][jb];
                }
            }
        }
    }

    free(vd);
    free(vt);
    free(vr);
}
