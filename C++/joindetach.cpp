#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;
#define NUM_THREADS 5

void *wait(void *t) {
  long tid;
  tid = (long)t;
  sleep(1);
  printf("Sleeping in thread \n");
  printf("Thread with id : %ld ...exiting \n", tid);
  pthread_exit(NULL);
}

int main() {
  long i;
  int rc;
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr[NUM_THREADS];
  void *status;
  auto gen = bind(uniform_int_distribution<>(0, 1), default_random_engine());
  // Initialize and set thread joinable
  for (i = 0; i < NUM_THREADS; i++) {
    cout << "main() : creating thread, " << i << endl;
    pthread_attr_init(&attr[i]);
    bool b = gen();
    if (b) {
      pthread_attr_setdetachstate(&attr[i], PTHREAD_CREATE_JOINABLE);
      cout << "Thread " << i << " joinable." << endl;
    } else {
      pthread_attr_setdetachstate(&attr[i], PTHREAD_CREATE_DETACHED);
      cout << "Thread " << i << " detached." << endl;
    }
    rc = pthread_create(&threads[i], NULL, wait, (void *)i);
    if (rc) {
      cout << "Error:unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  for (i = 0; i < NUM_THREADS; i++) {
    int state;
    pthread_attr_getdetachstate(&attr[i], &state);
    if (state == PTHREAD_CREATE_DETACHED)
      rc = pthread_detach(threads[i]);
    else
      rc = pthread_join(threads[i], &status);
    if (rc) {
      cout << "Error:unable to join," << rc << endl;
      exit(-1);
    }
    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr[i]);
    cout << "Main: completed thread id :" << i;
    cout << " exiting with status :" << status << endl;
  }
  cout << "Main: program exiting." << endl;
  pthread_exit(NULL);
}
