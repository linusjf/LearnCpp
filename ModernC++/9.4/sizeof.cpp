#include <iostream>
using namespace std;

struct Test {
  char a;
  alignas(double) char b;
};

int main(int __unused argc, char* __unused argv[]) {
  Test test;
  cout << "Size of Struct: " << sizeof(Test) << endl;
  cout << "Size of 'a': " << sizeof(test.a) << endl;
  cout << "Size of 'b': " << sizeof(test.b) << endl;
  cout << "Offset of 'a': " << (int)offsetof(struct Test, a) << endl;
  cout << "Offset of 'b': " << (int)offsetof(struct Test, b) << endl;
  return 0;
}
