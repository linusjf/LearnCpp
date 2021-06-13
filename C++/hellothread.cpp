#include <pthread.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define NUM_THREADS 5

void *printHello(void *threadid) {
  long tid = (long)threadid;
  char message[50];
  sprintf(message,"Hello, World! Thread ID, %ld\n",tid);
  clog << message;
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  for (long i = 0; i < NUM_THREADS; i++) {
    clog << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, printHello, (void *)i);
    if (rc) {
      clog << "Error:unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
