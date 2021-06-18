#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  string str = "Hello, world.";
  vector<string> v;
  // use push_back(const T&), copy
  v.push_back(str);
  // "str: Hello world."
  cout << "str: " << str << endl;
  // use push_back(const T&&), no copy
  // the string will be moved to vector, and therefore move can reduce copy cost
  v.push_back(move(str));
  // str is empty now
  cout << "str: " << str << endl;
  for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
    cout << *i << " ";
  cout << endl;
  return 0;
}
