#include <boost/heap/binomial_heap.hpp>
#include <iostream>

using namespace boost::heap;

int main() {
  binomial_heap<int> bh;
  bh.push(2);
  bh.push(3);
  bh.push(1);

  binomial_heap<int> bh2;
  bh2.push(4);
  bh.merge(bh2);

  for (auto it = bh.ordered_begin(); it != bh.ordered_end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << std::boolalpha << bh2.empty() << std::endl;
}
