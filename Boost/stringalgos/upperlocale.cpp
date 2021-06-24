#include <boost/algorithm/string.hpp>
#include <iostream>
#include <locale>
#include <string>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "Boost C++ k\xfct\xfcphaneleri";
  string upper_case1 = to_upper_copy(s);
  cout << upper_case1 << endl;
#ifdef LANG_TURKISH
  string upper_case2 = to_upper_copy(s, locale{"tr_TR"});
  locale::global(locale{"tr_TR"});
  cout << upper_case2 << endl;
#endif // LANG_TURKISH
}
