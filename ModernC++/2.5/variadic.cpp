#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename... Ts>
class Magic {};

class Magic<int, vector<int>, map<string, vector<int>>> darkMagic;

template <typename Require, typename... Args>
class MagicNext;

template <typename... Args>
void printf(const string& str, Args... args);

template <typename... Ts>
void magic(Ts... args) {
  cout << sizeof...(args) << endl;
}

template <typename T0>
void printf1(T0 value) {
  cout << value << endl;
}

template <typename T, typename... Ts>
void printf1(T value, Ts... args) {
  printf1(value);
  printf1(args...);
}

template <typename T0, typename... T>
void printf2(T0 t0, T... t) {
  cout << t0 << endl;
  if constexpr (sizeof...(t) > 0)
    printf2(t...);
}

template <typename T, typename... Ts>
auto printf3(T value, Ts... args) {
  cout << value << endl;
  (void)initializer_list<T>{([&args] { cout << args << endl; }(), value)...};
}

#include <iostream>
template <typename... T>
auto sum(T... t) {
  return (t + ...);
}

template <typename T, int BufSize>
class buffer_t {
 public:
  T& alloc();
  void free(T& item);

 private:
  T data[BufSize];
};

template <auto value>
void foo() {
  cout << value << endl;
  return;
}

int main() {
  magic();
  magic(1);
  magic(1, "");
  printf1(1, 2, "123", 1.1);
  printf2(1, 2, "123", 1.1);
  printf3(1, 2, "123", 1.1);
  cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
  buffer_t<int, 100> __unused buf;
  foo<10>();
  return 0;
}
