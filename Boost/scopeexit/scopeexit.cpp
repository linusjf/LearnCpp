#include <boost/scope_exit.hpp>
#include <iostream>

using namespace std;

int *foo()
{
  int *i = new int{10};
  BOOST_SCOPE_EXIT(&i)
  {
    delete i;
    i = 0;
  } BOOST_SCOPE_EXIT_END
  cout << *i << endl;
  return i;
}

int main()
{
  int *j = foo();
  cout << j << endl;
  cout << *j << endl;
}
