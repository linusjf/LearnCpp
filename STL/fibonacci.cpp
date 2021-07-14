#include <algorithm>
#include <iostream>

using namespace std;

class fibit {
  size_t i{0};
  size_t a{0};
  size_t b{1};

 public:
  size_t operator*() const {
    return b;
  }

  fibit& operator++() {
    const size_t old_b{b};
    b += a;
    a = old_b;
    ++i;
    return *this;
  }

  bool operator!=(const fibit& o) const {
    return i != o.i;
  }

 private:
  fibit() = default;

  explicit fibit(size_t i_) : i{i_} {
  }
  friend class fib_range;
};

namespace std {
template <>
struct iterator_traits<fibit> {
  using value_type = size_t;
  using iterator_category = forward_iterator_tag;
};
}  // namespace std
class fib_range {
  size_t end_n;

 public:
  fib_range(size_t end_n_) : end_n{end_n_} {
  }

  fibit begin() const {
    return fibit{};
  }

  fibit end() const {
    return fibit{end_n};
  }
};

int main() {
  for (size_t i: fib_range(10))
    cout << i << ", ";
  cout << endl;
}
