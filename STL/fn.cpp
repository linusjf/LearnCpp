#include <iostream>
using namespace std;
//maximum returns the maximum of the two elements
template <class T>
T maximum(T a, T b) {
  return a > b ? a : b;
}

int main() {
  cout << "maximum(10, 15) = " << maximum(10, 15) << endl;
  cout << "maximum('k', 's') = " << maximum('k', 's') << endl;
  cout << "maximum(10.1, 15.2) = " << maximum(10.1, 15.2) << endl;
}
