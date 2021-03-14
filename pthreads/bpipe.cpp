#include <iostream>
#include <queue>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

#include "BChannel.hpp"

typedef enum {EOS, TASK} Task_t;

class Task {
private:
  float x;
  Task_t tag;
public:

  Task(float x, Task_t tag):x(x),tag(tag) {}
  Task(Task_t tag):tag(tag)  {}

  bool isEos() {
    return(tag == EOS);
  }

  float get() {
    return(x);
  }

  void set(float y) {
    x = y;
    return;
  }

};

typedef struct __iochans {
  Channel<Task> *in;
  Channel<Task> *out;
} IO_Channels;

int ntasks = 0;

void * source(IO_Channels * chans) {
  // produce as many tasks as required
  for(int i=0; i<ntasks; i++) {
    Task t(((float) i), TASK);
    (chans->out)->send(t);
#ifdef TRACEMSG
    cout << "Source: output task " << i << endl;
#endif
  }
  cout << "Source: sending EOS" << endl;
  (chans->out)->send(*(new Task(EOS)));
#ifdef TRACEMSG
  cout << "Source: EOS Sent\n terminating ... " << endl;
#endif
  return(NULL);
}

void * square(IO_Channels * chans) {
  Task t = (chans->in)->receive();
  while(!t.isEos()) {
#ifdef TRACEMSG
    cout << "Stage1 received task " << t.get() << endl;
#endif
    float x = t.get();
    t.set(x*x);
    (chans->out)->send(t);
    t = (chans->in)->receive();
  }
#ifdef TRACEMSG
  cout << "Square: propagating EOS" << endl;
#endif
  (chans->out)->send(t); //eos
  return(NULL);
}

void * drain(IO_Channels * chans) {
  float sum = 0.0;
  int taskno = 0;
  Task t = (chans->in)->receive();
  while(!t.isEos()) {
#ifdef TRACEMSG
    cout << "Drain received task " << t.get() << endl;
#endif
    sum += t.get();
    taskno++;
    t = (chans->in)->receive();
  }
#ifdef TRACEMSG
  cout << "Drain: got EOS, terminating" << endl;
#endif
  cout << "Drain computed " << sum  << " from " << taskno << " tasks " << endl;
  return(NULL);

}

int main(int argc, char * argv[]) {
  // usage: a.out ntasks

  Channel<Task> ch12, ch23;
  IO_Channels stage1, stage2, stage3;
  pthread_t tid1, tid2, tid3;

  stage1.in = NULL;  stage1.out = &ch12;
  stage2.in = &ch12; stage2.out = &ch23;
  stage3.in = &ch23; stage3.out = NULL;

  ntasks = atoi(argv[1]);

  // start third stage
  if(pthread_create(&tid3, NULL, (void *(*)(void *))drain,
                    (void *) &stage3) != 0) {
    cout << "Error while creating stage3 " << endl;
    return(-1);
  }
  cout << "Drain started" << endl;


  // start second stage
  if(pthread_create(&tid2, NULL, (void *(*)(void *))square,
                    (void *) &stage2) != 0) {
    cout << "Error while creating stage2 " << endl;
    return(-1);
  }
  cout << "Square started!" << endl;

  // start first stage
  if(pthread_create(&tid1, NULL, (void *(*)(void *))source,
                    (void *) &stage1) != 0) {
    cout << "Error while creating stage1 " << endl;
    return(-1);
  }
  cout << "Source started " << endl;


  void * retval;
  pthread_join(tid3, &retval);

  return(0);
}
