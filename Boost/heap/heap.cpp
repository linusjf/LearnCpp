#include <boost/heap/priority_queue.hpp>
#include <iostream>

using namespace std;
using namespace boost::heap;

int main() {
  boost::heap::priority_queue<int> pq;
  pq.push(2);
  pq.push(3);
  pq.push(1);

  for (int i: pq)
    cout << i << " ";
  cout << endl;

  boost::heap::priority_queue<int> pq2;
  pq2.push(4);
  cout << boolalpha << (pq > pq2) << endl;
}
