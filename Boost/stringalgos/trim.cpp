#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::algorithm;

int main()
{
  string s = "\t Boost C++ Libraries \t";
  cout << "_" << trim_left_copy(s) << "_\n";
  cout << "_" << trim_right_copy(s) << "_\n";
  cout << "_" << trim_copy(s) << "_\n";
}
