#include <iostream>
#include <memory>

using namespace std;

class A;
class B;

class A {
 public:
  weak_ptr<B> pointer;
  ~A() {
    cout << "A was destroyed" << endl;
  }
};

class B {
 public:
  weak_ptr<A> pointer;
  ~B() {
    cout << "B was destroyed" << endl;
  }
};

int main() {
  shared_ptr<A> a = make_shared<A>();
  shared_ptr<B> b = make_shared<B>();
  a->pointer = b;
  b->pointer = a;
  return 0;
}
