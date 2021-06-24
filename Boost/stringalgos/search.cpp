#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "Boost C++ Libraries";
  boost::iterator_range<string::iterator> r = find_first(s, "C++");
  cout << r << endl;
  r = find_first(s, "xyz");
  cout << r << endl;
}
