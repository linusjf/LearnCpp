#include <iostream>

using namespace std;

void f(int *){}

void f_null() {
   f(nullptr);   // C2668
   // try one of the following lines instead
   f((int *) nullptr);
}

class MyClass {
public:
   int i;
};

int main() {
   MyClass * pMyClass = nullptr;
   if ( pMyClass == nullptr)
      cout << "pMyClass == nullptr" << endl;

   if ( pMyClass == 0)
      cout << "pMyClass == 0" << endl;

   pMyClass = 0;
   if ( pMyClass == nullptr)
      cout << "pMyClass == nullptr" << endl;

   if ( pMyClass == 0)
      cout << "pMyClass == 0" << endl;

   f_null();
}
