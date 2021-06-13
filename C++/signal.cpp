#include <unistd.h>
#include <csignal>
#include <iostream>
using namespace std;

void signalHandler(int signum) {
  cout << "Interrupt signal (" << signum << ") received.\n";
  // cleanup and close up stuff here
  // terminate program
  exit(signum);
}

int main() {
  // register signal SIGINT and signal handler
  signal(SIGINT, signalHandler);
  int i = 0;
  while (++i) {
    cout << "Going to sleep...." << endl;
    if (i == 10) 
      raise(SIGINT);
    sleep(1);
  }
  return 0;
}
