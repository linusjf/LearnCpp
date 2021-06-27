#include <boost/circular_buffer.hpp>
#include <iostream>

using namespace std;

int main() {
  typedef boost::circular_buffer<int> circular_buffer;
  circular_buffer cb{3};

  cb.push_back(0);
  cb.push_back(1);
  cb.push_back(2);
  cb.push_back(3);

  cout << boolalpha << cb.is_linearized() << endl;

  circular_buffer::array_range ar1, ar2;

  ar1 = cb.array_one();
  ar2 = cb.array_two();
  cout << ar1.second << ";" << ar2.second << endl;

  for (int i: cb)
    cout << i << endl;

  cb.linearize();

  ar1 = cb.array_one();
  ar2 = cb.array_two();
  cout << ar1.second << ";" << ar2.second << endl;
}
