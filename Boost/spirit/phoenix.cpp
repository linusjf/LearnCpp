#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <boost/phoenix/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;
//using boost::phoenix::ref;

int main() {
  string s;
  getline(cin, s);
  auto it = s.begin();
  int i;
  bool match =
      qi::phrase_parse(it, s.end(), qi::int_[boost::phoenix::ref(i) = qi::_1], ascii::space);
  cout << boolalpha << match << endl;
  if (match)
    cout << i << endl;
  if (it != s.end())
    cout << string{it, s.end()} << endl;
}
