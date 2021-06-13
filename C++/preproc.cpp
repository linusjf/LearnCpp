#include <iostream>
using namespace std;
#define DEBUG
#define MKSTR(x) #x
#define CONCAT(x, y) x##y

#define PI 3.14159

#define MIN(a, b) (((a) < (b)) ? a : b)

int main() {
  cout << "Value of PI: " << PI << endl;
  int i, j;
  i = 100;
  j = 30;
  cout << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
  cerr << "Trace: Inside main function" << endl;
#endif

#if 1
 /* This is commented part */
 cout << MKSTR(HELLO C++) << endl;
#endif

#if 0
 /* This is commented part */
 cout << MKSTR(HELLO C++) << endl;
#endif
  int xy = 100;
  cout << CONCAT(x, y) << endl;
  cout << "Value of __LINE__ : " << __LINE__ << endl;
  cout << "Value of __FILE__ : " << __FILE__ << endl;
  cout << "Value of __DATE__ : " << __DATE__ << endl;
  cout << "Value of __TIME__ : " << __TIME__ << endl;
  return 0;
}
