#include <iostream>

using namespace std;

class Base {
 public:
  int value1;
  int value2;

  Base() {
    value1 = 1;
  }

  // delegate Base() constructor
  Base(int value) : Base() {  
    value2 = value;
  }
};

int main() {
  Base b(2);
  cout << b.value1 << endl;
  cout << b.value2 << endl;
}
