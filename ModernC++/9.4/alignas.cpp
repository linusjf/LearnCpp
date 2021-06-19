#include <cstdlib>
#include <iostream>

int main() {
  alignas(16) int a[4];
  alignas(1024) int b[4];
  printf("%p\n", a);
  printf("%p\n", b);
  assert(alignof(a) == 16);
assert(alignof(b) == 1024);
}
