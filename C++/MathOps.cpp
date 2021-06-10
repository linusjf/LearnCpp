#include <cmath>
#include <iostream>
using namespace std;
int main() {
  // number definition:
  short s = 10;
  int i = -1000;
  long l = 100000;
  float f = 230.47;
  double d = 200.374;
  // mathematical operations;
  cout << "cos(s) :" << cos(s) << endl;
  cout << "sin(d) :" << sin(d) << endl;
  cout << "abs(i) :" << abs(i) << endl;
  cout << "floor(d) :" << floor(d) << endl;
  cout << "sqrt(f) :" << sqrt(f) << endl;
  cout << "sqrt(l) :" << sqrt(l) << endl;
  cout << "pow( d, 2) :" << pow(d, 2) << endl;
  int j;
  // set the seed
  srand((unsigned)time(NULL));
  /* generate 10 random numbers. */
  for (int i = 0; i < 10; i++) {
    // generate actual random number
    j = rand();
    cout << " Random Number : " << j << endl;
  }
  return 0;
}
