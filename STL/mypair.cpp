#include <type_traits>
using namespace std;
template <typename A, typename B>
struct MyPair {
  MyPair() {
  }
  MyPair(const A&, const B&) {
  }
};
int main() {
  MyPair mp{11, 22};
  static_assert(is_same_v<decltype(mp), MyPair<int, int>>);
}
