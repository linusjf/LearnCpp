#include <iostream>
#include <thread>

using namespace std;

int v = 1;

void critical_section(int change_v) {
  static mutex mtx;
  unique_lock<mutex> lock(mtx);
  // do contention operations
  v = change_v;
  cout << v << endl;
  // release the lock
  lock.unlock();
  // during this period,
  // others are allowed to acquire v
  // start another group of contention operations
  // lock again
  lock.lock();
  v += 1;
  cout << v << endl;
}

int main() {
  thread t1(critical_section, 2), t2(critical_section, 3);
  t1.join();
  t2.join();
  return 0;
}
