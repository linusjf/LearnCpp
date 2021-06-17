#include <iostream>
using namespace std;

void lambda_value_capture() {
  int value = 1;
  auto copy_value = [value] { return value; };
  value = 100;
  auto stored_value = copy_value();
  cout << "stored_value = " << stored_value << endl;
  // At this moment, stored_value == 1, and value == 100.
  // Because copy_value has copied when its was created.
}

void lambda_reference_capture() {
int value = 1;
auto copy_value = [&value] {
return value;
};
value = 100;
auto stored_value = copy_value();
cout << "stored_value = " << stored_value << endl;
// At this moment, stored_value == 100, value == 100.
// Because copy_value stores reference
}

void lambda_expression_capture() {
auto important = make_unique<int>(1);
auto add = [v1 = 1, v2 = move(important)](int x, int y) -> int {
return x+y+v1+(*v2);
};
cout << add(3,4) << endl;
}

void lambda_generic() {
auto generic = [](auto x, auto y) {
return x+y;
};
cout << generic(1, 2) << endl;
cout << generic(1.1, 2.2) << endl;
}

int main() {
  lambda_value_capture();
  lambda_reference_capture();
  lambda_expression_capture();
  lambda_generic();
}
