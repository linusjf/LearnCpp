#include <iostream>
#include <vector>

using namespace std;

void step(float *r, const float *d, int n);

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
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << r[i * n + j] << " ";
      if (j % 10 == 9)
        cout << endl;
    }
    cout << endl;
    cout << endl;
  }
  cout << "step: " << duration << " seconds" << endl;
  delete[] d;
}

void step(float *r, const float *d, int n) {
  vector<float> t(n * n);
#pragma omp parallel for shared(n,t,d)
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      t[n * j + i] = d[n * i + j];
    }
  }

#pragma omp parallel for shared(t,r,n)
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      float v = numeric_limits<float>::infinity();
      for (int k = 0; k < n; ++k) {
        float x = t[n * i + k];
        float y = t[n * k + j];
        float z = x + y;
        v = min(v, z);
      }
      r[n * i + j] = v;
    }
  }
}
