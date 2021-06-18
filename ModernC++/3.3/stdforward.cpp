#include <iostream>
#include <utility>

using namespace std;

void reference(int& __unused v) {
  cout << "lvalue reference" << endl;
}

void reference(int&& __unused v) {
  cout << "rvalue reference" << endl;
}

template <typename T>
void pass(T&& v) {
  cout << " normal param passing: ";
  reference(v);
  cout << " move param passing: ";
  reference(move(v));
  cout << " forward param passing: ";
  reference(forward<T>(v));
  cout << "static_cast<T&&> param passing: ";
  reference(static_cast<T&&>(v));
}

int main() {
  cout << "rvalue pass:" << endl;
  pass(1);
  cout << "lvalue pass:" << endl;
  int l = 1;
  pass(l);
  return 0;
}
