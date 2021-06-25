#include <boost/xpressive/regex_actions.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;
using namespace boost::xpressive;

int main() {
  string s = "Boost Libraries";
  ostream_iterator<string> it{cout, "\n"};
  sregex expr = (+_w)[*boost::xpressive::ref(it) = _] >> _s >> +_w;
  cout << boolalpha << regex_match(s, expr) << endl;
}
