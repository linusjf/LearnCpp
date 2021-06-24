#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "Boost C++ Libraries";
  vector<string> v;
  split(v, s, is_space());
  cout << v.size() << '\n';
}
