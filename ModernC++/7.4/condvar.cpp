#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

int main() {
  queue<int> produced_nums;
  mutex mtx;
  condition_variable cv;
  bool notified = false;  
  // notification sign
  auto producer = [&]() {
    for (int i = 0;; i++) {
      this_thread::sleep_for(chrono::milliseconds(500));
      unique_lock<mutex> lock(mtx);
      cout << "producing " << i << endl;
      produced_nums.push(i);
      notified = true;
      cv.notify_all();
    }
  };
  auto consumer = [&]() {
    while (true) {
      unique_lock<mutex> lock(mtx);
      while (!notified) {  // avoid spurious wakeup
        cv.wait(lock);
      }
      // temporal unlock to allow producer produces more rather than
      // let consumer hold the lock until its consumed.
      lock.unlock();
      this_thread::sleep_for(
          chrono::milliseconds(1000));  // consumer is slower
      lock.lock();
      if (!produced_nums.empty()) {
        cout << "consuming " << produced_nums.front() << endl;
        produced_nums.pop();
      }
      notified = false;
    }
  };
  thread p(producer);
  thread cs[2];
  for (int i = 0; i < 2; ++i) {
    cs[i] = thread(consumer);
  }
  p.join();
  for (int i = 0; i < 2; ++i) {
    cs[i].join();
  }
  return 0;
}
