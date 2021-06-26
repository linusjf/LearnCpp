#include <boost/bimap.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::bimap<boost::bimaps::set_of<string>,
                       boost::bimaps::set_of<int>>
      bimap;
  bimap animals;

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});

  cout << animals.left.count("spider") << endl;
  cout << animals.right.count(8) << endl;
}
