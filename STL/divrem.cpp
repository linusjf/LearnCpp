#include <iostream>
#include <utility>

using namespace std;

pair<int, int> divide_remainder(int dividend, int divisor) {
  pair<int, int> result;
  result.first = dividend / divisor;
  result.second = dividend % divisor;
  return result;
}

int main() {
  const auto result(divide_remainder(16, 3));
  cout << "16 / 3 is " << result.first << " with a remainder of "
            << result.second << '\n';
}
