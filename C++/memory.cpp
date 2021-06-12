#include <iostream>

using namespace std;

int main() {
  double* pvalue = new double;
  *pvalue = 29494.99;
  cout << "Value of pvalue : " << *pvalue << endl;
  delete pvalue;
  int ROW = 2;
  int COL = 3;
  double** ptr = new double*[ROW];  // Allocate memory for rows
  for (int i = 0; i < COL; i++) 
    ptr[i] = new double[COL];
  for (int i = 0; i < COL; i++) 
    delete[] ptr[i];
  delete[] ptr;
  return 0;
}
