#include <chrono>
#include <cmath>
#include <future>
#include <iostream>

using namespace std;

bool is_prime(int x) {
  for (int i = 2; i < sqrt(x); ++i)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  // call function asynchronously:
  future<bool> fut = async(is_prime, 444444443);

  // do something while waiting for function to set future:
  cout << "checking, please wait";
  chrono::milliseconds span(1);
  while (fut.wait_for(span) == future_status::timeout)
    cout << '.' << flush;

  // retrieve return value
  bool x = fut.get();  
  cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
  return 0;
}
