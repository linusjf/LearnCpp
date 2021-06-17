#include <iostream>

using namespace std;

class Foo {
  const char*&& right = "Rvalue";
 
  public:
  void bar() {
    // the string literal is a rvalue
    right = "still rvalue";
  }
};

int main() {
  // the string literal is an lvalue
  const char* const& left = "this is an lvalue";
  cout << left << endl;
}
