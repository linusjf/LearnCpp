#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::tokenizer<boost::escaped_list_separator<char>> tokenizer;
  string s = "Boost,\"C++ Libraries\"";
  tokenizer tok{s};
  for (const auto &t: tok)
    cout << t << endl;
}
