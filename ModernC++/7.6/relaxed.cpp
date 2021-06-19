#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
  atomic<int> counter = {0};
  vector<thread> vt;
  for (int i = 0; i < 100; ++i) {
    vt.emplace_back([&]() { counter.fetch_add(1, memory_order_relaxed); });
  }
  for (auto& t: vt) {
    t.join();
  }
  cout << "current counter:" << counter << endl;
}
