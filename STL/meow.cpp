#include <type_traits>
#include <utility>
#include <string>
using namespace std;

int main() {
  pair p(1729, "taxicab");
  pair p2(1729, (string)"taxicab");
  static_assert(is_same_v<decltype(p), pair<int, const char *>>);
  static_assert(is_same_v<decltype(p2), pair<int, string>>);
}
