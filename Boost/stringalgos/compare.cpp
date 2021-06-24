#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::algorithm;

int main()
{
  string s = "Boost C++ Libraries";
  cout.setf(ios::boolalpha);
  cout << starts_with(s, "Boost") << endl;
  cout << ends_with(s, "Libraries") << endl;
  cout << contains(s, "C++") << endl;
  cout << lexicographical_compare(s, "Boost") << endl;
}
