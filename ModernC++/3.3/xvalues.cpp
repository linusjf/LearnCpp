#include <iostream>
#include <string>

using namespace std;

void reference(string& __unused str) {
  cout << "lvalue" << endl;
}

void reference(string&& __unused str) {
  cout << "rvalue" << endl;
}

int main() {
  // lv1 is a lvalue
  string lv1 = "string,";
  // string&& r1 = s1; // illegal, rvalue can't ref to lvalue
  // legal, move can convert lvalue to rvalue
  string&& rv1 = move(lv1);
  // string,
  cout << rv1 << endl;  
  reference(rv1);
  // legal, const lvalue reference can extend temp variable's lifecycle
  const string& lv2 = lv1 + lv1;
  // lv2 += "Test"; // illegal, const ref can't be modified
  // string,string
  cout << lv2 << endl;
  // legal, rvalue ref extend lifecycle
  string&& rv2 = lv1 + lv2;
  // legal, non-const reference can be modified
  rv2 += "string";
  reference(rv2);
  // string,string,string,string
  cout << rv2 << endl;
  // output: lvalue
  reference(rv2);
  return 0;
}
