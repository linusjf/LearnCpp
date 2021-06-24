#include <boost/regex.hpp>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
  string s = "Boost k\xfct\xfcphaneleri";
  boost::basic_regex<char, boost::cpp_regex_traits<char>> expr;
  expr.imbue(locale{"tr_TR"});
  expr = "\\w+\\s\\w+";
  cout << boolalpha << boost::regex_match(s, expr) << '\n';
}
