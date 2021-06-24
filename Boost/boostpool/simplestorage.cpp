#include <boost/pool/simple_segregated_storage.hpp>
#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  boost::simple_segregated_storage<size_t> storage;
  vector<char> v(1024);
  storage.add_block(&v.front(), v.size(), 256);

  int *i = static_cast<int *>(storage.malloc());
  *i = 1;

  cout << "i = " << *i << endl;
  int *j = static_cast<int *>(storage.malloc_n(1, 512));
  j[10] = 2;
  cout << "j[10] = " << j[10] << endl;

  storage.free(i);
  storage.free_n(j, 1, 512);
}
