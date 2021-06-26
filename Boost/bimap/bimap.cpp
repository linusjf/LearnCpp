#include <boost/bimap.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::bimap<string, int> bimap;
  bimap animals;

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});

  cout << animals.left.count("cat") << endl;
  cout << animals.right.count(8) << endl;
}
