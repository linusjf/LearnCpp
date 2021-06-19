#include <iostream>
#include <string>

using namespace std;

string operator"" _wow1(const char *wow1, size_t __unused len) {
  return string(wow1) + "woooooooooow, amazing";
}
string operator"" _wow2(unsigned long long i) {
  return to_string(i) + "woooooooooow, amazing";
}

int main() {
  auto str = "abc"_wow1;
  auto num = 1_wow2;
  cout << str << endl;
  cout << num << endl;
  return 0;
}
