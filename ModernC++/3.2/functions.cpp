#include <iostream>

using namespace std;
// function pointer
using foo = void(int); 

void functional(foo f) {
f(1);
}

int main() {
auto f = [](int value) {
cout << value << endl;
};
// call by function pointer
functional(f); 
// call by lambda expression
f(1); 
return 0;
}
