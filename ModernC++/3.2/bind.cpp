#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

int foo(int a, int b, int c) {
  return a + b + c;
}

int main() {
  // bind parameter 1, 2 on function foo, and use std::placeholders::_1 as placeholder
  // for the first parameter.
  auto bindFoo = bind(foo, _1, 1, 2);
  // when call bindFoo, we only need one param left
  cout << bindFoo(1) << endl;
}
