#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template <typename C, typename T>
void insert_sorted(C &v, const T &item) {
  const auto insert_pos(lower_bound(begin(v), end(v), item));
  v.insert(insert_pos, item);
}

int main() {
  vector<string> v{"some", "random", "words", "without", "order", "aaa", "yyy"};
  assert(false == is_sorted(begin(v), end(v)));
  sort(begin(v), end(v));
  assert(true == is_sorted(begin(v), end(v)));
  insert_sorted(v, "zzz");
  for (const auto &w: v)
    cout << w << " ";
  cout << '\n';
}
