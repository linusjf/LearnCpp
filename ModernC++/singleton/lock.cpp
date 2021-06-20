#include <chrono>
#include <future>
#include <iostream>
#include <mutex>

using namespace std;

constexpr auto tenMill = 10000000;

mutex myMutex;

class MySingleton {
 public:
  static MySingleton& getInstance() {
    lock_guard<mutex> myLock(myMutex);
    if (!instance) {
      instance = new MySingleton();
    }
    // volatile int dummy{};
    return *instance;
  }

 private:
  MySingleton() = default;
  ~MySingleton() = default;
  MySingleton(const MySingleton&) = delete;
  MySingleton& operator=(const MySingleton&) = delete;

  static MySingleton* instance;
};

MySingleton* MySingleton::instance = nullptr;

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
