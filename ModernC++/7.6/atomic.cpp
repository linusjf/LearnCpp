#include <atomic>
#include <iostream>
#include <thread>

using namespace std;

atomic<int> cnt = {0};

int main() {
  thread t1([]() { cnt.fetch_add(1); });
  thread t2([]() {
    // identical to fetch_add
    cnt++;     
    // identical to fetch_add
    cnt += 1; 
  });
  t1.join();
  t2.join();
  cout << cnt << endl;
  return 0;
}
