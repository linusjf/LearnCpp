#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  string s = "Boost C++ Libraries";
  tokenizer tok{s};
  for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
    cout << *it << endl;
}
