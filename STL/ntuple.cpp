#include <cstdint>
#include <iostream>
#include <type_traits>

using namespace std;

template <class... Ts>
struct ntuple {};

template <class T, class... Ts>
struct ntuple<T, Ts...> : ntuple<Ts...> {
  ntuple(T t, Ts... ts) : ntuple<Ts...>(ts...), tail(t) {
  }
  T tail;
};

template <size_t, class>
struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, ntuple<T, Ts...>> {
  typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, ntuple<T, Ts...>> {
  typedef typename elem_type_holder<k - 1, ntuple<Ts...>>::type type;
};

template <size_t k, class... Ts>
typename enable_if<
    k == 0, typename elem_type_holder<0, ntuple<Ts...>>::type&>::type
get(ntuple<Ts...>& t) {
  return t.tail;
}

template <size_t k, class T, class... Ts>
typename enable_if<
    k != 0, typename elem_type_holder<k, ntuple<T, Ts...>>::type&>::type
get(ntuple<T, Ts...>& t) {
  ntuple<Ts...>& base = t;
  return get<k - 1>(base);
}

int main() {
ntuple<double, uint64_t, const char*> t1(12.2, 42, "big");

cout << "0th elem is " << get<0>(t1) << "\n";
cout << "1th elem is " << get<1>(t1) << "\n";
cout << "2th elem is " << get<2>(t1) << "\n";

get<1>(t1) = 103;
cout << "1th elem is " << get<1>(t1) << "\n";
}
