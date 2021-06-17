#include <functional>
#include <iostream>

using namespace std;

int foo(int para) {
return para;
}

int main() {
// function wraps a function that take int paremeter and returns int value
function<int(int)> func = foo;
int important = 10;
function<int(int)> func2 = [&](int value) -> int {
return 1+value+important;
};
cout << func(10) << endl;
cout << func2(10) << endl;
}
