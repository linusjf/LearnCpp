#include <boost/format.hpp>
#include <iostream>
#include <string>
using namespace std;

struct animal {
  string name;
  int legs;
};

ostream &operator<<(ostream &os, const animal &a) {
  return os << a.name << ',' << a.legs;
}

int main() {
  cout << boost::format{"%1%.%2%.%3%"} % 12 % 5 % 2014 << endl;
  cout << boost::format{"%2%.%1%.%3%"} % 12 % 5 % 2014 << endl;
  cout << boost::format{"%1% %2% %1%"} % boost::io::group(showpos, 1) % 2
       << endl;
  cout << boost::format{"%|1$+| %2% %1%"} % 1 % 2 << endl;
  cout << boost::format{"%+d %d %d"} % 1 % 2 % 1 << endl;
  cout << boost::format{"%|+| %|| %||"} % 1 % 2 % 1 << endl;
  cout << boost::format{"%+s %s %s"} % 1 % 2 % 1 << endl;
  animal a{"cat", 4};
  cout << boost::format{"%1%"} % a << endl;
  try
  {
    cout << boost::format{"%|+| %2% %1%"} % 1 % 2 << endl;
  }
  catch (boost::io::format_error &ex)
  {
    cout << ex.what() << endl;
  }
}
