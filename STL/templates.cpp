#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
using namespace std;

template <typename T1, typename T2, typename T3>
class my_wrapper {
  T1 t1;
  T2 t2;
  T3 t3;

 public:
  explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_) : t1{t1_}, t2{t2_}, t3{t3_} {
  }
};

template <typename T1, typename T2, typename T3>
my_wrapper<T1, T2, T3> make_wrapper(T1 t1, T2 t2, T3 t3) {
  return my_wrapper(t1, t2, t3);
}

template <typename T>
struct sum {
  T value;
  sum(T val) : value{val} {
  }
  template <typename... Ts>
  sum(T val, Ts&&... values) : value{val + (values + ...)} {
  }
  template <typename... Ts>
  sum(T val,Ts&&... ts) -> sum<std::common_type_t<T,Ts...>>;
};

int main() {
  // pair<int, const char*>
  [[maybe_unused]] pair my_pair(123, "abc");
  // tuple<int, double,
  [[maybe_unused]] tuple my_tuple(123, 12.3, "abc");
  [[maybe_unused]] my_wrapper<int, double, const char*> wrapper1{
      123, 1.23, "abc"};
  [[maybe_unused]] my_wrapper wrapper2{123, 1.23, "abc"};
  [[maybe_unused]] auto wrapper3(make_wrapper(123, 1.23, "abc"));

  sum<double> s{1u, 2.0, 3, 4.0f};
  sum<string> string_sum{std::string{"abc"}, "def"};

  std::cout << s.value << '\n' << string_sum.value << '\n';

  sum s2{1u, 2.0, 3, 4.0f};
  sum string_sum2{std::string{"abc"}, "def"};
  std::cout << s2.value << '\n' << string_sum2.value << '\n';
}
