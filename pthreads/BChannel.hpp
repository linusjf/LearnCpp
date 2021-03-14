#include <iostream>
#include <queue>

template<class Task> class Channel {

private:
  std::queue<Task> chan;
  pthread_mutex_t mutex;
  pthread_cond_t cond_r, cond_w;
  int max;
  int msgno;

public:

  Channel() {
    mutex  = PTHREAD_MUTEX_INITIALIZER;
    cond_r = PTHREAD_COND_INITIALIZER;
    cond_w = PTHREAD_COND_INITIALIZER;
    msgno  = 0;
    max = 4;
  }

  Channel(int bound):max(bound) {
    mutex  = PTHREAD_MUTEX_INITIALIZER;
    cond_r = PTHREAD_COND_INITIALIZER;
    cond_w = PTHREAD_COND_INITIALIZER;
    msgno  = 0;
  }


  void send(Task t) {
    pthread_mutex_lock(&mutex);
    while(msgno == max)
      pthread_cond_wait(&cond_w, &mutex);
    chan.push(t);
    msgno++;
    pthread_cond_signal(&cond_r);    // for waiting receives
    pthread_mutex_unlock(&mutex);
    return;
  }

  Task receive() {
    pthread_mutex_lock(&mutex);
    while(chan.empty()) 
      pthread_cond_wait(&cond_r, &mutex);
    Task t = chan.front();
    chan.pop();
    msgno--;
    pthread_cond_signal(&cond_w);
    pthread_mutex_unlock(&mutex);
    return(t);
  }
};
