#include <boost/unordered_map.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int stdmain();

int main() {
  typedef boost::unordered_map<string, int> unordered_map;
  unordered_map map;

  map.emplace("cat", 4);
  map.emplace("shark", 0);
  map.emplace("spider", 8);

  for (const auto &p: map)
    cout << p.first << ";" << p.second << endl;

  cout << map.size() << endl;
  cout << map.max_size() << endl;

  cout << boolalpha << (map.find("cat") != map.end()) << endl;
  cout << map.count("shark") << endl;
  stdmain();
}

int stdmain() {
  typedef std::unordered_map<string, int> unordered_map;
  unordered_map map;

  map.emplace("cat", 4);
  map.emplace("shark", 0);
  map.emplace("spider", 8);

  for (const auto &p: map)
    cout << p.first << ";" << p.second << endl;

  cout << map.size() << endl;
  cout << map.max_size() << endl;

  cout << boolalpha << (map.find("cat") != map.end()) << endl;
  cout << map.count("shark") << endl;
  return 0;
}
