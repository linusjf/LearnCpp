#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::algorithm;

int main()
{
  string s = "Boost C++ Libraries";
  boost::iterator_range<string::iterator> r =
    find_regex(s, boost::regex{"[\\w][+][+]"});
  cout << r << endl;
}
