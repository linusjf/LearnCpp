#include <iostream>
#include <string>

using namespace std;

template <typename... Ts>
auto sum(Ts... ts);

template <typename... Ts>
auto sum(Ts... ts) {
  return (ts + ...);
}

int main() {
  // Value: 15
  int the_sum{sum(1, 2, 3, 4, 5)};
  cout << the_sum << endl;
  string a{"Hello"};
  string b{"World"};
  // Output: Hello World
  std::cout << sum(a, ", ", b) << endl;
}
