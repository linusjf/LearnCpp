#include <boost/format.hpp>
#include <iostream>
using namespace std;

int main() {
  cout << boost::format{"%1%.%2%.%3%"} % 12 % 5 % 2014 << '\n';
  cout << boost::format{"%2%.%1%.%3%"} % 12 % 5 % 2014 << '\n';
}
