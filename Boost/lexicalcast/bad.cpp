#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  try {
    int i = boost::lexical_cast<int>("abc");
    cout << i << endl;
  } catch (const boost::bad_lexical_cast &e) {
    cerr << e.what() << endl;
  }
}
