#include <iostream>
#include <queue>

template<class Task> class Channel {

private:
  std::queue<Task> chan;
  pthread_mutex_t mutex;
  pthread_cond_t cond;

public:
  Channel() {
    mutex = PTHREAD_MUTEX_INITIALIZER;
    cond  = PTHREAD_COND_INITIALIZER;
  }


  void send(Task t) {
    pthread_mutex_lock(&mutex);
    chan.push(t);
    pthread_cond_signal(&cond);    // for waiting receives
    pthread_mutex_unlock(&mutex);
    return;
  }

  Task receive() {
    pthread_mutex_lock(&mutex);
    while(chan.empty()) {
      pthread_cond_wait(&cond, &mutex);
    }
    Task t = chan.front();
    chan.pop();
    pthread_mutex_unlock(&mutex);
    return(t);
  }
};
