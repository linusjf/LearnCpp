#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "Boost C++ Libraries";
  cout << "Original string; " << s << endl;
  cout << replace_first_copy(s, "+", "-") << endl;
  cout << replace_nth_copy(s, "+", 0, "-") << endl;
  cout << replace_last_copy(s, "+", "-") << endl;
  cout << replace_all_copy(s, "+", "-") << endl;
  cout << replace_head_copy(s, 5, "BOOST") << endl;
  cout << replace_tail_copy(s, 9, "LIBRARIES") << endl;
}
