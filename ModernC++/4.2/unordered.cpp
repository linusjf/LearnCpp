#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  // initialized in same order
  unordered_map<int, string> u = {{1, "1"}, {3, "3"}, {2, "2"}};
  map<int, string> v = {{1, "1"}, {3, "3"}, {2, "2"}};
  // iterates in the same way
  cout << "unordered_map" << endl;
  for (const auto& n: u)
    cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
  cout << endl;
  cout << "map" << endl;
  for (const auto& n: v)
    cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}
