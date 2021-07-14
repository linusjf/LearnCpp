#include <iostream>
#include <valarray>

using namespace std;

int main() {
  valarray<double> a{1.0, 2.0, 3.0};
  valarray<double> b{4.0, 5.0, 6.0};
  cout << (a * b).sum() << endl;
}
