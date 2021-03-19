#include <iostream>
#include <vector>

using namespace std;
typedef float float8_t __attribute__ ((ext_vector_type (8)));

void step(float *r, const float *d, int n);
constexpr float infty = numeric_limits<float>::infinity();

constexpr float8_t f8infty {
    infty, infty, infty, infty,
    infty, infty, infty, infty
};

static float8_t* float8_alloc(size_t n) {
    void* tmp = 0;
    if (posix_memalign(&tmp, sizeof(float8_t), sizeof(float8_t) * n)) 
        throw bad_alloc();
    return (float8_t*)tmp;
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
    z[i] = x[i] < y[i] ? x[i]: y[i];
  return z;
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
    // elements per vector
    constexpr int nb = 8;
    // vectors per input row
    int na = (n + nb - 1) / nb;

    // input data, padded, converted to vectors
    float8_t* vd = float8_alloc(n*na);
    // input data, transposed, padded, converted to vectors
    float8_t* vt = float8_alloc(n*na);

    #pragma omp parallel for
    for (int j = 0; j < n; ++j) {
        for (int ka = 0; ka < na; ++ka) {
            for (int kb = 0; kb < nb; ++kb) {
                int i = ka * nb + kb;
                vd[na*j + ka][kb] = i < n ? d_[n*j + i] : infty;
                vt[na*j + ka][kb] = i < n ? d_[n*i + j] : infty;
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float8_t vv = f8infty;
            for (int ka = 0; ka < na; ++ka) {
                float8_t x = vd[na*i + ka];
                float8_t y = vt[na*j + ka];
                float8_t z = x + y;
                vv = min8(vv, z);
            }
            r[n*i + j] = hmin8(vv);
        }
    }
    free(vt);
    free(vd);
}
