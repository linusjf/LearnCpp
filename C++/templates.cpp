#include <iostream>
#include <string>
using namespace std;

template <typename T>
inline T const& Max(T const& a, T const& b) {
  return a < b ? b : a;
}

template <typename T>
inline T const& Min(T const& a, T const& b) {
  return a < b ? a : b;
}

int main() {
  int i = 39;
  int j = 20;
  cout << "Max(" << i << "," <<  j << "): " << Max(i, j) << endl;
  cout << "Min(" << i << "," <<  j << "): " << Min(i, j) << endl;
  double f1 = 13.5;
  double f2 = 20.7;
  char str[20];
  sprintf(str, "Max(%2.1f, %2.1f): ", f1,f2);
  cout << str << Max(f1, f2) << endl;
  sprintf(str, "Min(%2.1f, %2.1f): ", f1,f2);
  cout << str << Min(f1, f2) << endl;
  string s1 = "Hello";
  string s2 = "World";
  sprintf(str, "Max(%5s, %5s): ", s1.c_str(),s2.c_str());
  cout << str << Max(s1, s2) << endl;
  sprintf(str, "Min(%5s, %5s): ", s1.c_str(),s2.c_str());
  cout << str << Min(s1, s2) << endl;
  return 0;
}
