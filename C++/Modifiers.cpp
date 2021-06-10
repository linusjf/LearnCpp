#include <iostream>
using namespace std;
/* This program shows the difference between
* signed and unsigned integers.
*/
int main()
{
 // a signed short integer
 short int i; 
 // an unsigned short integer
 short unsigned int j; 

 j = 50000;
 i = j;
 cout << i << " " << j;
 return 0;
}
