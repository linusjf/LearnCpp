#include <boost/unordered_set.hpp>
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int stdmain();

int main() {
  typedef boost::unordered_set<string> unordered_set;
  unordered_set set;

  set.emplace("cat");
  set.emplace("shark");
  set.emplace("spider");

  for (const string &s: set)
    cout << s << endl;

  cout << set.size() << endl;
  cout << set.max_size() << endl;

  cout << boolalpha << (set.find("cat") != set.end()) << endl;
  cout << set.count("shark") << endl;
  stdmain();
}

int stdmain() {
  typedef std::unordered_set<string> unordered_set;
  unordered_set set;

  set.emplace("cat");
  set.emplace("shark");
  set.emplace("spider");

  for (const string &s: set)
    cout << s << endl;

  cout << set.size() << endl;
  cout << set.max_size() << endl;

  cout << boolalpha << (set.find("cat") != set.end()) << endl;
  cout << set.count("shark") << endl;
  return 0;
}
