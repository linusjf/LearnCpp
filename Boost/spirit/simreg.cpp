#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;

int main() {
  string s;
  getline(cin, s);
  auto it = s.begin();
  bool match = qi::phrase_parse(it, s.end(), +ascii::digit, ascii::space);
  cout << boolalpha << match << endl;
  if (it != s.end())
    cout << string{it, s.end()} << endl;
}
