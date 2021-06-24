#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Boost Libraries";
  boost::regex expr{"(\\w+)\\s(\\w+)"};
  boost::smatch what;
  if (boost::regex_search(s, what, expr)) {
    cout << what[0] << endl;
    cout << what[1] << "_" << what[2] << endl;
  }
}
