#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

#pragma omp parallel
  {
#pragma omp single
    cout << "Start loop" << endl;
#pragma omp for
    for (int i = 0; i < 10; ++i)
      cout << i;
#pragma omp single
    cout << endl << "End loop" << endl;
  }
  //    Expected output will be similar to this:
  //    the begin of loop
  //    6378049152
  //    the end of loop
  return 0;
}
