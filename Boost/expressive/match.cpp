#include <boost/xpressive/xpressive.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::xpressive;

int main() {
  string s = "Boost Libraries";
  sregex expr = sregex::compile("\\w+\\s\\w+");
  cout << boolalpha << regex_match(s, expr) << '\n';
}
