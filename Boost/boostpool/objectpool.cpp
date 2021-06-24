#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;

int main()
{
  boost::object_pool<int> pool;

  int *i = pool.malloc();
  *i = 1;

  int *j = pool.construct(2);
  cout << *i << *j << endl;
  pool.destroy(i);
  pool.destroy(j);
}
