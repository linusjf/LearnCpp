#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Boost Libraries";
  boost::regex expr{"\\w+\\s\\w+"};
  cout << boolalpha << boost::regex_match(s, expr) << endl;
}
