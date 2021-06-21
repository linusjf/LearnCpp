#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>

using namespace std;

void do_work(int i) {
  char str[20];
  sprintf(str,"Thread %d\n",i);
  cout << str;
}

int main() {
  vector<thread> threads;
  for (unsigned i = 0; i < 20; ++i) {
    threads.push_back(thread(do_work, i));
  }
  for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
}
