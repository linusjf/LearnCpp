#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>
#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  boost::ptr_vector<int> v;
  array<int, 3> a{{0, 1, 2}};
  copy(a.begin(), a.end(), boost::ptr_container::ptr_back_inserter(v));
  cout << v.size() << '\n';
}
