#include <boost/xpressive/xpressive.hpp>
#include <iostream>

using namespace std;
using namespace boost::xpressive;

int main() {
  const char *c = "Boost Libraries";
  cregex expr = cregex::compile("\\w+\\s\\w+");
  cout << boolalpha << regex_match(c, expr) << endl;
}
