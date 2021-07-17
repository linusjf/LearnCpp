#include <iomanip>
#include <iostream>

using namespace std;
template <typename T>
bool pair_comparer(T a, T b) {
  return a == b;
}

template <typename T>
bool pair_comparer([[maybe_unused]] T a) {
  return false;
}

template <typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
  return a == b && pair_comparer(args...);
}

int main() {
  cout << boolalpha << pair_comparer(1.5, 1.5, 2, 2, 6, 6) << endl;
  cout << boolalpha << pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7) << endl;
}
