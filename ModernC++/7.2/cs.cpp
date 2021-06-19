#include <iostream>
#include <thread>

using namespace std;

int v = 1;

void critical_section(int change_v) {
  static mutex mtx;
  lock_guard<mutex> lock(mtx);
  // execute contention works
  v = change_v;
  // mtx will be released after leaving the scope
}

int main() {
  thread t1(critical_section, 2), t2(critical_section, 3);
  t2.join();
  t1.join();
  cout << v << endl;
  return 0;
}
