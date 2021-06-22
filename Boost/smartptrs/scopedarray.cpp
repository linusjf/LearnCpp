#include <boost/scoped_array.hpp>
#include <iostream>
using namespace boost;
using namespace std;

int main()
{
  scoped_array<int> p{new int[2]};
  *p.get() = 1;
  p[1] = 2;
  cout << p[0] << p[1] << endl;
  p.reset(new int[3]);
}
