#include <pthread.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define NUM_THREADS 5

struct thread_data {
  int thread_id;
  const char *message;
};

void *printHello(void *threadarg) {
  struct thread_data *my_data;
  my_data = (struct thread_data *)threadarg;
  char outstr[100];
  sprintf(outstr, "Thread ID: %d Message: %s\n", my_data->thread_id, my_data->message);
  cout << outstr;
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  struct thread_data td[NUM_THREADS];
  int rc;
  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    cout << "main() : creating thread, " << i << endl;
    td[i].thread_id = i;
    td[i].message = "This is the message";
    rc = pthread_create(&threads[i], NULL, printHello, (void *)&td[i]);
    if (rc) {
      cout << "Error:unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
