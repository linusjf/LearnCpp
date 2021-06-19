#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main() {
// pack a lambda expression that returns 7 into a packaged_task
packaged_task<int()> task([](){return 7;});
// get the future of task
future<int> result = task.get_future(); // run task in a thread
thread(move(task)).detach();
cout << "waiting...";
// block until future has arrived
result.wait(); 
// output result
cout << "done!" <<  endl << "future result is " << result.get() << endl;
return 0;
}
