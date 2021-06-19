#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main() {
  promise<int> p;
  future<int> f = p.get_future();

  thread t([&p] {
    try {
      // code that may throw
      throw runtime_error("Example");
    } catch (...) {
      try {
        // store anything thrown in the promise
        p.set_exception(current_exception());
      } catch (...) {
      }  // set_exception() may throw too
    }
  });

  try {
    cout << f.get();
  } catch (const exception& e) {
    cout << "Exception from the thread: " << e.what() << '\n';
  }
  t.join();
}
