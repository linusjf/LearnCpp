#include <iostream>
#include <memory>

using namespace std;

struct Foo {
  Foo() {
    cout << "Foo::Foo" << endl;
  }

  ~Foo() {
    cout << "Foo::~Foo" << endl;
  }

  void foo() {
    cout << "Foo::foo" << endl;
  }
};

void f(const Foo &) {
  cout << "f(const Foo&)" << endl;
}

int main() {
  unique_ptr<Foo> p1(make_unique<Foo>());
  // p1 is not empty, prints
  if (p1)
    p1->foo();
  {
    unique_ptr<Foo> p2(move(p1));
    // p2 is not empty, prints
    f(*p2);
    // p2 is not empty, prints
    if (p2)
      p2->foo();
    // p1 is empty, no prints
    if (p1)
      p1->foo();
    p1 = move(p2);
    // p2 is empty, no prints
    if (p2)
      p2->foo();
    cout << "p2 was destroyed" << endl;
  }
  // p1 is not empty, prints
  if (p1)
    p1->foo();
  // Foo instance will be destroyed when leaving the scope
}
