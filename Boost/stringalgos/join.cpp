#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost::algorithm;

int main() {
  vector<string> v{"Boost", "C++", "Libraries"};
  cout << join(v, " ") << '\n';
}
