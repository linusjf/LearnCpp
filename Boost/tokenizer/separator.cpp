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
  boost::char_separator<char> seps{" ", "+"};
  tokenizer toks{s, seps};
  for (const auto &t: toks)
    cout << t << endl;
  boost::char_separator<char> sep2{" ", "+", boost::keep_empty_tokens};
  tokenizer tok2{s, sep2};
  for (const auto &t : tok2)
    cout << t << endl;
}
