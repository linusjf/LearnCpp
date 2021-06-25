#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::spirit;

int main()
{
  string s;
  getline(cin, s);
  auto it = s.begin();
  bool match = qi::phrase_parse(it, s.end(),
    qi::lexeme[ascii::digit >> ascii::digit], ascii::space);
  cout << boolalpha << match << endl;
  if (it != s.end())
    cout << string{it, s.end()} << endl;
}
