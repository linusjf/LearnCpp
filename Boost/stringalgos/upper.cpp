#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::algorithm;

int main()
{
  string s = "Boost C++ Libraries";
  cout << to_upper_copy(s) << endl;
}
