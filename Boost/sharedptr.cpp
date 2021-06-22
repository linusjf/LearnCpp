#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;

int main()
{
  shared_ptr<int> p1{new int{1}};
  cout << *p1 << '\n';
  shared_ptr<int> p2{p1};
  p1.reset(new int{2});
  cout << *p1.get() << '\n';
  p1.reset();
  cout << boolalpha << static_cast<bool>(p1) << '\n';
  cout << boolalpha << static_cast<bool>(p2) << '\n';
  p2.reset();
  cout << boolalpha << static_cast<bool>(p2) << '\n';
}
