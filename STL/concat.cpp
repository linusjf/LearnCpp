#include <functional>
#include <iostream>

using namespace std;
template <typename T, typename... Ts>
auto concat(T t, Ts... ts) {
  if constexpr (sizeof...(ts) > 0) 
    return [=](auto... parameters) { return t(concat(ts...)(parameters...)); };
   else 
    return t;
}

template <typename F, typename G, typename H>
auto concatt(F f, G g, H h) {
  return [=](auto... params) { return f(g(h(params...))); };
}

int main() {
  auto twice([](int i) { return i * 2; });
  auto thrice([](int i) { return i * 3; });
  auto combined(concat(twice, thrice, plus<int>{}));
  auto combinedt(concatt(twice, thrice, plus<int>{}));
  cout << combined(2, 3) << endl;
  cout << combinedt(2, 3) << endl;
}
