#include <thread>

using namespace std;

void do_something(int __unused i) {
}

struct func {
  int& i;
  func(int& i_) : i(i_) {
  }
  
  void operator()() {
    for (unsigned int j = 0; j < 1000000; ++j) {
      // i refers to a destroyed variable
      do_something(i);  
    }
  }
};

int main() {
  int some_local_state = 0;
  func my_func(some_local_state);
  thread my_thread(my_func);
  // don't wait the thread to finish
  my_thread.detach(); 
}
// i is destroyed, but the thread is likely still running..
