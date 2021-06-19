#include <atomic>
#include <iostream>
#include <utility>

using namespace std;

struct A {
  float x;
  int y;
  long long z;
};

struct B {
  int arr[100];
};

struct C {
  int e, f;
};

int main() {
  atomic<A> a;
  atomic<B> b;
  atomic<C> c;
  cout << boolalpha << "atomic<A> is lock free? " << a.is_lock_free() << endl;
  cout << boolalpha << "atomic<B> is lock free? " << b.is_lock_free() << endl;
  cout << "atomic<C> is lock free? " << c.is_lock_free() << endl;
  return 0;
}
