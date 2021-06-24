#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "Boost C++ Libraries";
  cout << "Original string: " << s << endl;
  cout << erase_first_copy(s, "s") << endl;
  cout << erase_nth_copy(s, "s", 0) << endl;
  cout << erase_last_copy(s, "s") << endl;
  cout << erase_all_copy(s, "s") << endl;
  cout << erase_head_copy(s, 5) << endl;
  cout << erase_tail_copy(s, 9) << endl;
}
