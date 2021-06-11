#include <iostream>

using namespace std;

int main( )
{
 const char *str = "Hello, C++";
 cout << "Value of str is : " << str << endl;

 char name[50];
 cout << "Please enter your name: ";
 cin >> name;
 cout << "Your name is: " << name << endl;

 const char *readstr = "Unable to read....";
 cerr << "Error message : " << readstr << endl;

 clog << "Error message : " << readstr << endl;
}
