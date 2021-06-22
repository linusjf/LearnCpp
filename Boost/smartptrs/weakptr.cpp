#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <thread>
#include <functional>
#include <iostream>

using namespace std;

void reset(shared_ptr<int> &sh)
{
  sh.reset();
}

void print(weak_ptr<int> &w)
{
  shared_ptr<int> sh = w.lock();
  if (sh)
    cout << *sh << '\n';
}

int main()
{
  shared_ptr<int> sh{new int{99}};
  weak_ptr<int> w{sh};
  thread t1{reset, ref(sh)};
  thread t2{print, ref(w)};
  t1.join();
  t2.join();
}
