#include <cstddef>
#include <functional>
#include <string>
#include <unordered_set>

using namespace std;

struct animal {
  string name;
  int legs;
};

auto hashfn = [](const animal& n) {
  return (hash<string>()(n.name) ^ hash<int>()(n.legs));
};
auto equalfn = [](const animal& lhs, const animal& rhs) {
  return lhs.name == rhs.name && lhs.legs == rhs.legs;
};

int main() {
  typedef unordered_set<animal, decltype(hashfn), decltype(equalfn)>
      unordered_set;
  unordered_set animals(8,hashfn,equalfn);

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});
}
