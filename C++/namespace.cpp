#include <iostream>
using namespace std;
// first name space
namespace first_space {
void func() {
  cout << "Inside first_space" << endl;
}
// second name space
namespace second_space {
void func() {
  cout << "Inside second_space" << endl;
}
}  // namespace second_space
}  // namespace first_space

namespace third_space {
void func() {
  cout << "Inside third_space" << endl;
}
}  // namespace third_space

using namespace first_space::second_space;

int main() {
  third_space::func();
  func();
  return 0;
}
