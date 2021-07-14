#include <iostream>
using namespace std;
int main() {
  auto greet_john_doe([] { cout << "Hello, John Doe" << endl; });
  greet_john_doe();
}
