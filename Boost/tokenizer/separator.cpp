#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  string s = "Boost C++ Libraries";
  boost::char_separator<char> sep{" "};
  tokenizer tok{s, sep};
  for (const auto &t: tok)
    cout << t << endl;
}
