#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Boost Libraries";
  boost::regex expr{"\\w+"};
  boost::regex_token_iterator<string::iterator> it{s.begin(), s.end(), expr};
  boost::regex_token_iterator<string::iterator> end;
  while (it != end)
    cout << *it++ << endl;
}
