#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int> i) {
  (*i)++;
}

int main() {
  // auto pointer = new int(10); // illegal, no direct assignment
  // Constructed a shared_ptr
  auto pointer = make_shared<int>(10);
  foo(pointer);
  // 11
  cout << *pointer << endl;
  // The shared_ptr will be destructed before leaving the scope

  // reference count+1
  auto pointer2 = pointer;
  // reference count+1
  auto pointer3 = pointer;
  int __unused *p = pointer.get();
  // no increase of reference count
  // 3
  cout << "pointer.use_count() = " << pointer.use_count() << endl;
  // 3
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;  
  // 3
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;  
  pointer2.reset();
  cout << "reset pointer2:" << endl;
  // 2
  cout << "pointer.use_count() = " << pointer.use_count() << endl;  
  // 0, pointer2 has reset
  cout << "pointer2.use_count() = " << pointer2.use_count()
       << endl;  
  // 2
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;
  pointer3.reset();
  cout << "reset pointer3:" << endl;
  // 1
  cout << "pointer.use_count() = " << pointer.use_count() << endl;    
  // 0
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
  // 0, pointer
  cout << "pointer3.use_count() = " << pointer3.use_count()
       << endl;  

  return 0;
}
