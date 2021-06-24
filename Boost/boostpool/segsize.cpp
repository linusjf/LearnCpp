#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;

int main()
{
  boost::object_pool<int> pool{32, 0};
  pool.construct();
  cout << pool.get_next_size() << endl;
  pool.set_next_size(8);
  cout << pool.get_next_size() << endl;
}
