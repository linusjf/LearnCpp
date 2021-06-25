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
  vector<int> v;
  if (qi::phrase_parse(it, s.end(), qi::int_ % ',', ascii::space, v)) {
    ostream_iterator<int> out{cout, " "};
    copy(v.begin(), v.end(), out);
  }
  cout << endl;
}
