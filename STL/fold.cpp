#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

template <typename... Ts>
auto sum(Ts... ts) {
  return (ts + ...);
}

template <typename R, typename... Ts>
auto matches(const R& range, Ts... ts) {
  return (count(begin(range), end(range), ts) + ...);
}

template <typename T, typename... Ts>
bool insert_all(T& set, Ts... ts) {
  return (set.insert(ts).second && ...);
}

template <typename T, typename... Ts>
bool within(T min, T max, Ts... ts) {
  return ((min <= ts && ts <= max) && ...);
}

template <typename T, typename... Ts>
void insert_all(vector<T>& vec, Ts... ts) {
  (vec.push_back(ts), ...);
}

int main() {
  // Value: 15
  int the_sum{sum(1, 2, 3, 4, 5)};
  cout << the_sum << endl;
  string a{"Hello"};
  string b{"World"};
  // Output: Hello World
  cout << sum(a, ", ", b) << endl;

  vector<int> v{1, 2, 3, 4, 5};
  // returns 2
  cout << matches(v, 2, 5) << endl;
  // returns 0
  cout << matches(v, 100, 200) << endl;
  // returns 0
  cout << matches("abcdefg", 'x', 'y', 'z') << endl;
  // returns 3
  cout << matches("abcdefg", 'a', 'd', 'f') << endl;
  set<int> my_set{1, 2, 3};
  // Returns true
  cout << boolalpha << insert_all(my_set, 4, 5, 6) << endl;
  // Returns false, because the 2 collides
  cout << boolalpha << insert_all(my_set, 7, 8, 2) << endl;

  // --> false
  cout << boolalpha << within(10, 20, 1, 15, 30) << endl;
  // --> true
  cout << boolalpha << within(10, 20, 11, 12, 13) << endl;
  // --> true
  cout << boolalpha << within(5.0, 5.5, 5.1, 5.2, 5.3) << endl;

  string aaa{"aaa"};
  string bcd{"bcd"};
  string def{"def"};
  string zzz{"zzz"};
  // --> true
  cout << boolalpha << within(aaa, zzz, bcd, def) << endl;
  // --> false
  cout << boolalpha << within(aaa, def, bcd, zzz) << endl;
  vector<int> v1{1, 2, 3};
  insert_all(v1, 4, 5, 6);
  insert_all(v1);
}
