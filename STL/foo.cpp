#include <iostream>
using namespace std;

// non template function to call with zero arguments
void Foo() {
  cout << " ";
}

// base template with 1 argument (which will be called from the variadic one).
template <typename Arg>
void Foo(Arg arg) {
  cout << __PRETTY_FUNCTION__ << "\n";
  cout << arg << " ";
}

// variadic template with one or more arguments.
// ellipsis (...) operator to the left of the parameter name declares a parameter pack,
// allowing you to declare zero or more parameters (of different types).
template <typename First, typename... Args>
void Foo(First first, Args... args) {
  cout << __PRETTY_FUNCTION__ << "\n";
  Foo(first);
  Foo(args...);
  //  ellipsis (...) operator to the right of the parameter name will cause
  //  the whole expression that precedes the ellipsis to be repeated for every
  //  subsequent argument unpacked from the argument pack, with the expressions
  //  separated by commas.
}

int main() {
  string one = "One";
  const char* two = "Two";
  float three = 3.3333333333;

  Foo();  // non template
  cout << endl;

  Foo(one);  // base template
  cout << endl;

  Foo(one, two);  // variadic argument template
  cout << endl;

  Foo(one, two, three);  // variadic argument template
  cout << endl;

  Foo(1, 2, three, 4, 5.7, 6 / 2, "lalala");  // variadic argument template
  cout << endl;
}
