#include <iostream>
#include <vector>

using namespace std;

void step(float *r, const float *d, int n);
constexpr float infty = numeric_limits<float>::infinity();

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
/*  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << r[i * n + j] << " ";
      if (j % 10 == 9)
        cout << endl;
    }
    cout << endl;
    cout << endl;
  } */
  cout << "step: " << duration << " seconds" << endl;
  delete[] d;
}

void step(float *r, const float *d_, int n) {
constexpr int nb = 4;
    int na = (n + nb - 1) / nb;
    int nab = na*nb;

    // input data, padded
    vector<float> d(n*nab, infty);
    // input data, transposed, padded
    vector<float> t(n*nab, infty);

    #pragma omp parallel for
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            d[nab*j + i] = d_[n*j + i];
            t[nab*j + i] = d_[n*i + j];
        }
    }

# pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float vv[nb];
            for (int kb = 0; kb < nb; ++kb) 
                vv[kb] = infty;
            for (int ka = 0; ka < na; ++ka) {
                for (int kb = 0; kb < nb; ++kb) {
                    float x = d[nab*i + ka * nb + kb];
                    float y = t[nab*j + ka * nb + kb];
                    float z = x + y;
                    vv[kb] = min(vv[kb], z);
                }
            }
            // v = result for k = 0, 1, 2, ...
            float v = infty;
            for (int kb = 0; kb < nb; ++kb) 
                v = min(vv[kb], v);
            r[n*i + j] = v;
        }
    }
}
