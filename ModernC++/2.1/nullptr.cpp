#include <iostream>
#include <type_traits>

using namespace std;

void foo(char *);

void foo(int);

int main() {
if (is_same<decltype(NULL), decltype(0)>::value)
cout << "NULL == 0" << endl;
if (is_same<decltype(NULL), decltype((void*)0)>::value)
cout << "NULL == (void *)0" << endl;
if (is_same<decltype(NULL), nullptr_t>::value)
cout << "NULL == nullptr" << endl;
// will call foo(int)
foo(0); 
// doesn't compile
// foo(NULL); 
// will call foo(char*)
foo(nullptr); 
return 0;
}

void foo(char *) {
std::cout << "foo(char*) is called" << std::endl;
}

void foo(int __unused i) {
std::cout << "foo(int) is called" << std::endl;
}
