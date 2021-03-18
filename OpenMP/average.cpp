#include <iostream>
#include <omp.h>

using namespace std;

void avg_round_robin();
void avg_reduction();

int main() {
  avg_round_robin();
  avg_reduction();
  return 0;
}

void avg_round_robin() {
  int N = 600000000;
  double tavg = 0;

  double timer_start = omp_get_wtime();
  omp_set_num_threads(omp_get_max_threads());
#pragma omp parallel
  {
    double avg = 0.0;
    int id = omp_get_thread_num();
    int nthreads = omp_get_num_threads();

    for (int i = id; i < N; i += nthreads)
      avg += i;
#pragma omp atomic
    tavg += avg;
  }
  double timer_elapsed = omp_get_wtime() - timer_start;
  tavg = tavg / N;

  cout << "Round robin : " << endl;
  cout << tavg << " took " << timer_elapsed << endl;
}

void avg_reduction() {
  int N = 600000000;
  int j = 0;
  double tavg = 0;

  double timer_start = omp_get_wtime();
  omp_set_num_threads(omp_get_max_threads());

#pragma omp parallel for reduction(+ : tavg)
  for (j = 0; j < N; ++j)
    tavg += j;

  double timer_elapsed = omp_get_wtime() - timer_start;
  tavg = tavg / N;

  cout << "Reduce : " << endl;
  cout << tavg << " took " << timer_elapsed << endl;
}
