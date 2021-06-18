#include <iostream>
#include <utility>

using namespace std;

void reference(int& __unused v) {
cout << "lvalue reference" << endl;
}

void reference(int&& __unused v) {
cout << "rvalue reference" << endl;
}

template <typename T>
void pass(T&& v) {
cout << " normal param passing: ";
reference(v);
}

int main() {
cout << "rvalue pass:" << endl;
pass(1);
cout << "lvalue pass:" << endl;
int l = 1;
pass(l);
return 0;
}
