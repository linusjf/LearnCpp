#include <boost/spirit/include/qi.hpp>
#include <boost/variant.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost::spirit;

template <typename Iterator, typename Skipper>
struct my_grammar
    : qi::grammar<Iterator, vector<boost::variant<int, bool>>(), Skipper> {
  my_grammar() : my_grammar::base_type{values} {
    value = qi::int_ | qi::bool_;
    values = value % ',';
  }

  qi::rule<Iterator, boost::variant<int, bool>(), Skipper> value;
  qi::rule<Iterator, vector<boost::variant<int, bool>>(), Skipper> values;
};

struct print : public boost::static_visitor<> {
  template <typename T>
  void operator()(T t) const {
    cout << boolalpha << t << ' ';
  }
};

int main() {
  string s;
  getline(cin, s);
  auto it = s.begin();
  my_grammar<string::iterator, ascii::space_type> g;
  vector<boost::variant<int, bool>> v;
  if (qi::phrase_parse(it, s.end(), g, ascii::space, v)) {
    for (const auto &elem: v)
      boost::apply_visitor(print(), elem);
  }
  cout << endl;
}
