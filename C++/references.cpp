#include <ctime>
#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double &getValues(int i) {
  // return a reference to the ith element
  return vals[i];
}

// main function to call above defined function.
int main() {
  cout << "Value before change" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "vals[" << i << "] = ";
    cout << vals[i] << endl;
  }
  // change 2nd element
  getValues(1) = 20.23; 
  // change 4th element
  getValues(3) = 70.8;  
  cout << "Value after change" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "vals[" << i << "] = ";
    cout << vals[i] << endl;
  }
  return 0;
}
