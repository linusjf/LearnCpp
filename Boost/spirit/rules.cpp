#include <algorithm>
#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
using namespace boost::spirit;

int main() {
  string s;
  getline(cin, s);
  auto it = s.begin();
  qi::rule<string::iterator, vector<int>(), ascii::space_type> values =
      qi::int_ % ',';
  vector<int> v;
  if (qi::phrase_parse(it, s.end(), values, ascii::space, v)) {
    ostream_iterator<int> out{cout, " "};
    copy(v.begin(), v.end(), out);
  }
  cout << endl;
}
