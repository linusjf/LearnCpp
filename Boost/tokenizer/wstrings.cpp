#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::tokenizer<boost::char_separator<wchar_t>,
                           wstring::const_iterator,
                           wstring>
      tokenizer;
  wstring s = L"Boost C++ Libraries";
  boost::char_separator<wchar_t> sep{L" "};
  tokenizer tok{s, sep};
  for (const auto &t: tok)
    wcout << t << endl;
}
