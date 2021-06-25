#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;

int main() {
  wstring s;
  getline(wcin, s);
  auto it = s.begin();
  bool match = qi::phrase_parse(
      it, s.end(), ascii::digit, ascii::space, qi::skip_flag::dont_postskip);
  wcout << boolalpha << match << endl;
  if (it != s.end())
    wcout << wstring{it, s.end()} << endl;
}
