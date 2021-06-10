#include <iostream>

using namespace std;

int main() {
  // actual variable declaration.
  int var = 20; 
  // pointer variable
  int *ip = &var;    
  cout << "Value of var variable: ";
  cout << var << endl;
  // print the address stored in ip pointer variable
  cout << "Address stored in ip variable: ";
  cout << ip << endl;
  // access the value at the address available in pointer
  cout << "Value of *ip variable: ";
  cout << *ip << endl;
  return 0;
}
