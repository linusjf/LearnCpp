#include <iostream>

using namespace std;

class A {
 public:
  int* pointer;

  A() : pointer(new int(1)) {
    cout << "construct" << pointer << endl;
  }
  
  // meaningless object copy
  A(A& a) : pointer(new int(*a.pointer)) {
    cout << "copy" << pointer << endl;
  }  
  
  A(A&& a) : pointer(a.pointer) {
    a.pointer = nullptr;
    cout << "move" << pointer << endl;
  }
  
  ~A() {
    cout << "destruct" << pointer << endl;
    delete pointer;
  }
};

// avoid compiler optimization
A return_rvalue(bool test) {
  A a, b;
  // equal to static_cast<A&&>(a);
  if (test)
    return a;
  else
    // equal to static_cast<A&&>(b);
    return b;
}

int main() {
  A obj = return_rvalue(false);
  cout << "obj:" << endl;
  cout << obj.pointer << endl;
  cout << *obj.pointer << endl;
  return 0;
}
