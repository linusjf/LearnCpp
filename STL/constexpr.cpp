#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class addable {
  T val;

 public:
  addable(T v) : val{v} {
  }

  template <typename U>
  T add(U x) const {
    if constexpr (is_same_v<T, vector<U>>) {
      auto copy(val);
      for (auto& n: copy) {
        n += x;
      }
      return copy;
    } else {
      return val + x;
    }
  }
};

template <typename T>
class addableold {
  T val;

 public:
  addableold(T v) : val{v} {
  }
  template <typename U>
  std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T> add(U x) const {
    return val + x;
  }
  template <typename U>
  std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>> add(
      U x) const {
    auto copy(val);
    for (auto& n: copy) {
      n += x;
    }
    return copy;
  }
};

int oldmain() {
  addableold<int>{1}.add(2);           // is 3
  addableold<float>{1.0}.add(2);       // is 3.0
  addableold<string>{"aa"}.add("bb");  // is "aabb"
  vector<int> v{1, 2, 3};
  v = addableold<vector<int>>{v}.add(10);
  for (auto const& c: v)
    std::cout << c << ' ';
  cout << endl;
  // is vector<int>{11, 12, 13}
  vector<string> sv{"a", "b", "c"};
  sv = addableold<vector<string>>{sv}.add(string{"z"});
  // is {"az", "bz", "cz"}
  for (auto const& c: sv)
    std::cout << c << ' ';
  cout << endl;
  return 0;
}

int main() {
  addable<int>{1}.add(2);           // is 3
  addable<float>{1.0}.add(2);       // is 3.0
  addable<string>{"aa"}.add("bb");  // is "aabb"
  vector<int> v{1, 2, 3};
  v = addable<vector<int>>{v}.add(10);
  for (auto const& c: v)
    std::cout << c << ' ';
  cout << endl;
  // is vector<int>{11, 12, 13}
  vector<string> sv{"a", "b", "c"};
  sv = addable<vector<string>>{sv}.add(string{"z"});
  // is {"az", "bz", "cz"}
  for (auto const& c: sv)
    std::cout << c << ' ';
  cout << endl;
  oldmain();
}
