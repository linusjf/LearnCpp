#include <iostream>
using namespace std;

template <class T>
class X {
 public:
  static T s;
};

template <class T>
T X<T>::s = 0;
template <>
int X<int>::s = 3;
template <>
char* X<char*>::s = (char*)"Hello";

template <class T>
void f(T t) {
  static T s = 0;
  s = t;
  cout << "s = " << s << endl;
}

int main() {
  X<int> xi;
  cout << "xi.s = " << xi.s << endl;
  X<char*> xc;
  cout << "xc.s = " << xc.s << endl;
  f(10);
  f("Hello");
  return 0;
}
