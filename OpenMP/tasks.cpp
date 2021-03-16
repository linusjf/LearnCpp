#include <iostream>
#include <list>
#include <omp.h>
#include <unistd.h>

static void processElement(unsigned n) {
// Tell who am I. The #pragma omp critical ensures that
// only one thread sends data to std::cout
#pragma omp critical
  std::cout << "Thread " << omp_get_thread_num() << " processing element " << n
            << std::endl;

  // Simulate some work
  usleep(n * 1000);
}

int main(void) {
  std::list<unsigned> lst;

  // Fill the list
  for (unsigned u = 0; u < 16; ++u)
    lst.push_back(1 + u);

    // Now process each element of the list in parallel

#pragma omp parallel // Create a parallel region
#pragma omp single   // Only one thread will instantiate tasks
  {
    for (auto element : lst) {
#pragma omp task firstprivate(element)
      processElement(element);
    }

// Wait for all tasks to be finished
#pragma omp taskwait
  }

  return 0;
}
