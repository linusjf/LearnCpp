#include <iostream>

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

virtual void foo() = 0;
};

class Subclass : public Base {
public:
// inheritance constructor
using Base::Base; 
void foo() {};
};

int main() {
Subclass s(3);
std::cout << s.value1 << std::endl;
std::cout << s.value2 << std::endl;
}
