#include <iostream>
using namespace std;

struct Storage {
  char a;
  int b;
  double c;
  long long d;
};

struct alignas(max_align_t) AlignasStorage {
  char a;
  int b;
  double c;
  long long d;
};

int main() {
  cout << alignof(Storage) << endl;
  cout << alignof(AlignasStorage) << endl;
  return 0;
}
