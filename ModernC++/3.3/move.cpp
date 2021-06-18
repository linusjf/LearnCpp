#include <iostream>

using namespace std;


int main() {
  // int &a = move(1); // illegal, non-const lvalue reference cannot ref rvalue
  // legal, const lvalue reference can
  const int &b = move(1);
  cout << b << endl;
}
