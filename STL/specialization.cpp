#include <cstring>
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

//maximum returns the maximumimum of the two elements
template <class T>
T maximum(T a, T b) {
  return a > b ? a : b;
}

// Specialization of maximum for char*
template <>
char* maximum(char* a, char* b) {
  return strcmp(a, b) > 0 ? a : b;
}

int main() {
  stream<int> si;
  stream<char> sc;
  si.f();
  sc.f();
  // generates an instantiation from the base template
  [[maybe_unused]] X<char, char> xcc;
  //generates an instantiation from the partial specialization
  [[maybe_unused]] X<char, int> xii;
  cout << "maximum(10, 15) = " << maximum(10, 15) << endl;
  cout << "maximum('k', 's') = " << maximum('k', 's') << endl;
  cout << "maximum(10.1, 15.2) = " << maximum(10.1, 15.2) << endl;
  cout << "maximum(\"Aladdin\", \"Jasmine\") = "
       << maximum("Aladdin", "Jasmine") << endl;
  return 0;
}
