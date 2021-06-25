#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;

int main() {
  string s;
  getline(cin, s);
  auto it = s.begin();
  int i;
  if (qi::phrase_parse(it, s.end(), qi::int_, ascii::space, i))
    cout << i << endl;
}
