#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]);

//****************************************************************************80

int main(int argc, char *argv[])

//****************************************************************************80
//
//  Purpose:
//
//    HELLO has each thread print out its ID.
//
//  Discussion:
//
//    HELLO is a "Hello, World" program for OpenMP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 May 2010
//
//  Author:
//
//    John Burkardt
//
{
  int id;
  double wtime;

  cout << endl;
  cout << "HELLO_OPENMP" << endl;
  cout << "  C++/OpenMP version" << endl;

  cout << endl;
  cout << "  Number of processors available = " << omp_get_num_procs() << "\n";
  cout << "  Number of threads =              " << omp_get_max_threads()
       << endl;

  wtime = omp_get_wtime();
//
//  Have each thread say hello
//
#pragma omp parallel private(id)
  {
    id = omp_get_thread_num();
#pragma omp critical
    cout << "  This is process " << id << endl;
  }
  //
  //  Finish up by measuring the elapsed time.
  //
  wtime = omp_get_wtime() - wtime;
  //
  //  Terminate.
  //
  cout << endl;
  cout << "HELLO_OPENMP" << endl;
  cout << "  Normal end of execution." << endl;

  cout << endl;
  cout << "  Elapsed wall clock time = " << wtime << endl;

  return 0;
}
