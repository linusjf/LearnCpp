#include <cstdint>
template <class... Ts>
struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
  tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {
  }

  T tail;
};

int main() {
  tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
}
