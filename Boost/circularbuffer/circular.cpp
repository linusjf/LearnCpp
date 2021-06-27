#include <boost/circular_buffer.hpp>
#include <iostream>

using namespace std;

int main() {
  typedef boost::circular_buffer<int> circular_buffer;
  circular_buffer cb{3};

  cout << "capacity = " << cb.capacity() << endl;
  cout << "size = " << cb.size() << endl;

  cb.push_back(0);
  cb.push_back(1);
  cb.push_back(2);

  cout << "size = " << cb.size() << endl;

  for (int i: cb)
    cout << i << " ";
  cout << endl;

  cb.push_back(3);
  cb.push_back(4);
  cb.push_back(5);

  cout << "size = " << cb.size() << endl;

  for (int i: cb)
    cout << i << " ";
  cout << endl;
}
