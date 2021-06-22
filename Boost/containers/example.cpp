#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class animal {
 public:
  string name;
  int legs;
  bool hastail;

  animal(string n, int l, bool b): name(n), legs(l), hastail(b) {
  }
  
  inline bool operator < (const animal& a) const {
    return legs < a.legs;
  }   
};

int main() {
  vector<animal> animals;
  animal bear("bear", 2, false);
  animal man("man", 2, false);
  animal kangaroo("kangaroo", 2, true);
  animal gorilla("gorilla", 2, false);
  animal lion("lion", 4, true);
  animal tiger("tiger", 4, true);
 
  animals.push_back(lion);
  animals.push_back(tiger);
  animals.push_back(bear);
  animals.push_back(man);
  animals.push_back(kangaroo);
  animals.push_back(gorilla);

  sort(animals.begin(),animals.end());

  for (auto i = animals.begin(); i != animals.end(); i++)
    cout << (*i).name << " ";
  cout << endl;
}
