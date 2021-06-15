#include <iostream>

#define LEN 10

int len_foo() {
  int i = 2;
  return i;
}

constexpr int len_foo_constexpr() {
  return 5;
}

constexpr int fibonacci(const int n) {
  return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  // legal
  char __unused arr_1[10];
  char __unused arr_2[LEN];
  int len = 10;
  // char arr_3[len]; // illegal
  const int __unused len_2 = len + 1;
  constexpr int len_2_constexpr = 1 + 2 + 3;
  // char arr_4[len_2]; // illegal, but ok for most of the compilers
  char __unused arr_4[len_2_constexpr];  // legal
  // char arr_5[len_foo()+5]; // illegal
  char __unused arr_6[len_foo_constexpr() + 1];  // legal
  // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
  std::cout << fibonacci(10) << std::endl;
  return 0;
}
