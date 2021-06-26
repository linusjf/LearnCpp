#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index_container.hpp>
#include <iostream>
#include <string>
#include <utility>

using namespace std;
using namespace boost::multi_index;

class animal {
 public:
  animal(string name, int legs) : name_{move(name)}, legs_(legs) {
  }
  bool operator<(const animal &a) const {
    return legs_ < a.legs_;
  }
  const string &name() const {
    return name_;
  }

 private:
  string name_;
  int legs_;
};

typedef multi_index_container<
    animal,
    indexed_by<
        ordered_unique<identity<animal> >,
        hashed_unique<const_mem_fun<animal, const string &, &animal::name> > > >
    animal_multi;

int main() {
  animal_multi animals;

  animals.emplace("cat", 4);
  animals.emplace("shark", 0);
  animals.emplace("spider", 8);

  cout << animals.begin()->name() << endl;

  const auto &name_index = animals.get<1>();
  cout << name_index.count("shark") << endl;
}
