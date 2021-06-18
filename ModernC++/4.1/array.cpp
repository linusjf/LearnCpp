#include <array>
#include <iostream>
using namespace std;

void foo(int* __unused p, int __unused len) {
  return;
}

int main() {
  array<int, 4> arr = {1, 2, 3, 4};
  cout << "is array empty? " << arr.empty() << endl;
  // check if container is empty
  arr.size();   // return the size of the container
  // iterator support
  for (auto __unused& i: arr) {
    // ...
  }
  // use lambda expression for sort
  sort(arr.begin(), arr.end(), [](int a, int b) { return b < a; });
  // array size must be constexpr
  constexpr int len = 4;
  array<int, len> arr2 = {1, 2, 3, 4};
  // illegal, different than C-style array, array will not deduce to T*
  // int *arr_p = arr;
  array<int, 4> __unused arr3 = {1, 2, 3, 4};
  // C-stype parameter passing
  // foo(arr, arr.size()); // illegal, cannot convert implicitly
  foo(&arr2[0], arr2.size());
  foo(arr2.data(), arr2.size());
  // use `sort`
  sort(arr2.begin(), arr2.end());
}
