#include <stdexcept>
#include <iostream>
#include <thread>

using namespace std;

void do_something(int __unused i) {
}

void do_something_in_current_thread() {
}

class scoped_thread {
  thread t;

 public:
  explicit scoped_thread(thread t_) : t(move(t_)) {
    if (!t.joinable())
      throw logic_error("No thread");
  }

  ~scoped_thread() {
    cout << "Calling join..." << endl;
    t.join();
  }
 
  scoped_thread(scoped_thread const&) = delete;
  scoped_thread& operator=(scoped_thread const&) = delete;
};

struct func {
  int& i;
 
  func(int& i_) : i(i_) {
  }
  
  void operator()() {
    for (unsigned j = 0; j < 1000000; ++j) {
      do_something(i);
    }
  }
};

int main() {
  int some_local_state;
  scoped_thread t{(thread(func(some_local_state)))};
  do_something_in_current_thread();
}
