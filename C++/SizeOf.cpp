#include <iostream>
using namespace std;
typedef int feet;
enum color { red, green = 5, blue };

int main() {

  cout << "Size of bool : " << sizeof(bool) << endl;
  cout << "Size of char : " << sizeof(char) << endl;
  cout << "Size of int : " << sizeof(int) << endl;
  cout << "Size of short int : " << sizeof(short int) << endl;
  cout << "Size of long int : " << sizeof(long int) << endl;
  cout << "Size of float : " << sizeof(float) << endl;
  cout << "Size of double : " << sizeof(double) << endl;
  cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
  cout << "Size of feet : " << sizeof(feet) << endl;
  cout << "Size of color : " << sizeof(color) << endl;
  return 0;
}
