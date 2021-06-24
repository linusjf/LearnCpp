#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = " Boost Libraries ";
  boost::regex expr{"\\s"};
  string fmt{"_"};
  cout << boost::regex_replace(s, expr, fmt) << '\n';
}
