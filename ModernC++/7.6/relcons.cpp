#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
  // initialize as nullptr to prevent consumer load a dangling pointer
  atomic<int*> ptr(nullptr);
  int v;
  thread producer([&]() {
    int* p = new int(42);
    v = 1024;
    ptr.store(p, memory_order_release);
  });
  thread consumer([&]() {
    int* p;
    while (!(p = ptr.load(memory_order_consume)))
      ;
    cout << "p: " << *p << endl;
    cout << "v: " << v << endl;
  });
  producer.join();
  consumer.join();
}
