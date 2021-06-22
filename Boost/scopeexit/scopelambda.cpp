#include <iostream>
#include <utility>

using namespace std;

template <typename T>
struct scope_exit {
  scope_exit(T &&t) : t_{move(t)} {
  }
  ~scope_exit() {
    t_();
  }
  T t_;
};

template <typename T>
scope_exit<T> make_scope_exit(T &&t) {
  return scope_exit<T>{move(t)};
}

int *foo() {
  int *i = new int{10};
  auto cleanup = make_scope_exit([&i]() mutable {
    delete i;
    i = 0;
  });
  cout << *i << endl;
  return i;
}

int main() {
  int *j = foo();
  cout << j << endl;
  cout << *j << endl;
}
