#include <iostream>
#include <thread>

using namespace std;

int main() {
  thread t([]() { cout << "Hello, world!" << endl; });
  t.join();
  return 0;
}
