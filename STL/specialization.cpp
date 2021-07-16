#include <iostream>
using namespace std;

template <class T>
class stream {
 public:
  void f() {
    cout << "stream<T>::f()" << endl;
  }
};

template <>
class stream<char> {
 public:
  void f() {
    cout << "stream<char>::f()" << endl;
  }
};

template <typename T1, typename T2>
class X {};

//partial specialization
//C2989 here
template <typename T1>
class X<T1, int> {};

int main() {
  stream<int> si;
  stream<char> sc;
  si.f();
  sc.f();
  // generates an instantiation from the base template
  [[maybe_unused]] X<char, char> xcc;
  //generates an instantiation from the partial specialization
  [[maybe_unused]] X<char, int> xii;
  return 0;
}
