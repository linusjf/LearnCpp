#include <mutex>

using namespace std;

class MyObjectClass {};

void swap(MyObjectClass& lhs, MyObjectClass& rhs);

class X {
 private:
  MyObjectClass myObj;
  mutex m;

 public:
  X(MyObjectClass const& obj) : myObj(obj) {
  }
  friend void swap(X& lhs, X& rhs) {
    // the arguments are checked to ensure they are different instances,
    // because attempting to acquire a lock on a mutex
    // when we already hold it is undefined behavior.
    if (&lhs == &rhs)
      return;

    // the call to lock() locks the two mutexes
    lock(lhs.m, rhs.m);

    // two lock_guard instances are constructed one for each mutex.
    lock_guard<mutex> lock_a(lhs.m, adopt_lock);
    lock_guard<mutex> lock_b(rhs.m, adopt_lock);

    swap(lhs.myObj, rhs.myObj);
  }
};
