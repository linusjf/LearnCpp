#include <atomic>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

constexpr auto tenMill = 10000000;

class MySingleton {
 public:
  static MySingleton* getInstance() {
    MySingleton* sin = instance.load();
    if (!sin) {
      lock_guard<mutex> myLock(myMutex);
      sin = instance.load();
      if (!sin) {
        sin = new MySingleton();
        instance.store(sin);
      }
    }
    // volatile int dummy{};
    return sin;
  }

 private:
  MySingleton() = default;
  ~MySingleton() = default;
  MySingleton(const MySingleton&) = delete;
  MySingleton& operator=(const MySingleton&) = delete;
  static atomic<MySingleton*> instance;
  static mutex myMutex;
};

atomic<MySingleton*> MySingleton::instance;
mutex MySingleton::myMutex;

chrono::duration<double> getTime() {
  auto begin = chrono::system_clock::now();
  for (size_t i = 0; i <= tenMill; ++i) {
    MySingleton::getInstance();
  }
  return chrono::system_clock::now() - begin;
};

int main() {
  auto fut1 = async(launch::async, getTime);
  auto fut2 = async(launch::async, getTime);
  auto fut3 = async(launch::async, getTime);
  auto fut4 = async(launch::async, getTime);
  auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();
  cout << total.count() << endl;
}
