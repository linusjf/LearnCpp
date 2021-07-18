#include <experimental/algorithm>
#include <experimental/functional>
#include <iostream>
#include <experimental/iterator>
#include <string>

using namespace std::experimental;
using namespace std;

template <typename Itr>
static void print(Itr it, size_t chars) {
  copy_n(it, chars, ostream_iterator<char>{cout});
  cout << endl;
}

int main() {
  const string long_string{
      "Lorem ipsum dolor sit amet, consetetur"
      " sadipscing elitr, sed diam nonumy eirmod"};
  const string needle{"elitr"};
  {
    auto match(search(
        begin(long_string), end(long_string), begin(needle), end(needle)));
    print(match, 5);
  }
  {
    auto match(std::search(begin(long_string),
                      end(long_string),
                      std::default_searcher(begin(needle), end(needle))));
    print(match, 5);
  }
  {
    auto match(std::search(begin(long_string),
                      end(long_string),
                      boyer_moore_searcher(begin(needle), end(needle))));
    print(match, 5);
  }
  {
    auto match(
        std::search(begin(long_string),
               end(long_string),
               boyer_moore_horspool_searcher(begin(needle), end(needle))));
    print(match, 5);
  }
}
