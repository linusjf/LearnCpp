#include <iostream>
#include <vector>

using namespace std;

// Consider an actual class.
class Obj {
  static int i, j;

 public:
  void f() const {
    cout << i++ << " ";
  }

  void g() const {
    cout << j++ << " ";
  }
};

// Static member definitions:
int Obj::i = 10;
int Obj::j = 12;

// Implement a container for the above class
class ObjContainer {
  vector<Obj*> a;

 public:
  void add(Obj* obj) {
    // call vector's standard method.
    a.push_back(obj); 
  }

  friend class SmartPointer;
};

// implement smart pointer to access member of Obj class.
class SmartPointer {
  ObjContainer oc;
  unsigned long index;

 public:
  SmartPointer(ObjContainer& objc) {
    oc = objc;
    index = 0;
  }

  // Return value indicates end of list:
  bool operator++()  // Prefix version
  {
    if (index >= oc.a.size())
      return false;
    if (oc.a[++index] == 0)
      return false;
    return true;
  }
 
  // Postfix version
  bool operator++(int)  
  {
    return operator++();
  }
 
  // overload operator->
  Obj* operator->() const {
    if (!oc.a[index]) {
      cout << "Zero value";
      return (Obj*)0;
    }
    return oc.a[index];
  }
};

int main() {
  const int sz = 10;
  Obj o[sz];
  ObjContainer oc;
  for (int i = 0; i < sz; i++) {
    oc.add(&o[i]);
  }
  // Create an iterator
  SmartPointer sp(oc);  
  do {
    // smart pointer call
    sp->f();  
    sp->g();
  } while (sp++);
  cout << endl;
  return 0;
}
