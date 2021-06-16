#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // using find with array and pointer:
  int myints[] = {10, 20, 30, 40};
  int* p;

  p = find(myints, myints + 4, 30);
  if (p != myints + 4)
    cout << "Element found in myints: " << *p << '\n';
  else
    cout << "Element not found in myints\n";

  // using find with vector and iterator:
  vector<int> myvector(myints, myints + 4);
  vector<int>::iterator it;

  it = find(myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    cout << "Element found in myvector: " << *it << '\n';
  else
    cout << "Element not found in myvector\n";
  return 0;
}
