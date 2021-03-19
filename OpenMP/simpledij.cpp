#include <iostream>

using namespace std;

void step(float* r, const float* d, int n);

int main(int argc, char **argv) {
    constexpr int n = 3;
    const float d[n*n] = {
        0, 8, 2,
        1, 0, 9,
        4, 5, 0,
    };
    float r[n*n];
    step(r, d, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << r[i*n + j] << " ";
        cout << endl;
    }
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
