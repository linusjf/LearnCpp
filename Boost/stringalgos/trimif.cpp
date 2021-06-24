#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::algorithm;

int main() {
  string s = "--Boost C++ Libraries--";
  cout << trim_left_copy_if(s, is_any_of("-")) << endl;
  cout << trim_right_copy_if(s, is_any_of("-")) << endl;
  cout << trim_copy_if(s, is_any_of("-")) << endl;
  s = "123456789Boost C++ Libraries123456789";
  cout << trim_left_copy_if(s, is_digit()) << endl;
  cout << trim_right_copy_if(s, is_digit()) << endl;
  cout << trim_copy_if(s, is_digit()) << endl;
}
