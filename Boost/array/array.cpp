#include <algorithm>
#include <boost/array.hpp>
#include <iostream>
#include <string>

using namespace std;
int main() {
  typedef boost::array<string, 3> array;
  array a;

  a[0] = "cat";
  a.at(1) = "zebra";
  *a.rbegin() = "spider";

  sort(a.begin(), a.end());

  for (const string &s: a)
    cout << s << endl;

  cout << a.size() << endl;
  cout << a.max_size() << endl;
}
