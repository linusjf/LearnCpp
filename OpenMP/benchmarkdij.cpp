#include <iostream>

using namespace std;

void step(float* r, const float* d, int n);

float* generate_dists(int n) {
 float *d = (float *) new float[n * n];
 for (int i = 0; i < n; i++)
   for (int j = 0; j < n; j++)
     *(d + i * n + j) = i == j ? 0.0f: (float)(rand() % 100 + 1);
 return d;
}

int main(int argc, char **argv) {
    constexpr int n = 1000;
    srand(time(NULL));
    const float *d = generate_dists(n);
    cout << "Generated" << endl;
    float r[n*n];
    step(r, d, n);
    cout << "Stepped" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << r[i*n + j] << " ";
        cout << endl;
    }
    delete [] d;
}

void step(float* r, const float* d, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float v = numeric_limits<float>::infinity();
            for (int k = 0; k < n; ++k) {
                float x = d[n*i + k];
                float y = d[n*k + j];
                float z = x + y;
                v = min(v, z);
            }
            r[n*i + j] = v;
        }
    }
}
