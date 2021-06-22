#include <boost/scoped_ptr.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main()
{
  scoped_ptr<int> p{new int{1}};
  cout << *p << '\n';
  p.reset(new int{2});
  cout << *p.get() << '\n';
  p.reset();
  cout << boolalpha << static_cast<bool>(p) << '\n';
}
