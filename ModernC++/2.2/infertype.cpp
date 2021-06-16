#include <iostream>
using namespace std;

template <typename T, typename U>
auto add2(T x, U y) -> decltype(x + y) {
  return x + y;
}

template <typename T, typename U>
auto add3(T x, U y) {
  return x + y;
}

std::string lookup1();
std::string& lookup2();

std::string look_up_a_string_1() {
  return lookup1();
}

std::string& look_up_a_string_2() {
  return lookup2();
}

decltype(auto) look_up_a_string_11() {
  return lookup1();
}

decltype(auto) look_up_a_string_22() {
  return lookup2();
}

int main() {
  auto x = 1;
  auto y = 2;
  decltype(x + y) z;
  if (is_same<decltype(x), int>::value)
    cout << "type x == int" << endl;
  if (is_same<decltype(x), float>::value)
    cout << "type x == float" << endl;
  if (is_same<decltype(x), decltype(z)>::value)
    cout << "type z == type x" << endl;

  // after c++11
  auto w = add2<int, double>(1, 2.0);
  if (is_same<decltype(w), double>::value) {
    cout << "w is double: ";
  }
  cout << w << endl;
  // after c++14
  auto q = add3<double, int>(1.0, 2);
  cout << "q: " << q << endl;
}
