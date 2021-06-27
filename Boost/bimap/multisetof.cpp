#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {
  typedef boost::bimap<boost::bimaps::set_of<string>,
                       boost::bimaps::multiset_of<int>>
      bimap;
  bimap animals;

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"dog", 4});

  cout << animals.left.count("dog") << endl;
  cout << animals.right.count(4) << endl;
}
