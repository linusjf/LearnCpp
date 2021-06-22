#include <algorithm>
#include <boost/ptr_container/ptr_vector.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class animal {
 public:
  string name;
  int legs;
  bool hastail;

  animal(string n, int l, bool b) : name(n), legs(l), hastail(b) {
  }

  inline bool operator<(const animal& a) const {
    return legs < a.legs;
  }
};

int main() {
  boost::ptr_vector<animal> animals;
  animals.push_back(new animal("bear", 2, false));
  animals.push_back(new animal("man", 2, false));
  animals.push_back(new animal("kangaroo", 2, true));
  animals.push_back(new animal("gorilla", 2, false));
  animals.push_back(new animal("lion", 4, true));
  animals.push_back(new animal("tiger", 4, true));

  sort(animals.begin(), animals.end());
  for (auto i = animals.begin(); i != animals.end(); i++)
    cout << (*i).name << " ";
  cout << endl;
}
