#include <iostream>
#include <vector>

using namespace std;

int main() {
  // constructors used in the same order as described above:
  vector<int> first;           
  // four ints with value 100
  vector<int> second(4, 100);  
  // iterating through second
  vector<int> third(second.begin(),
                         second.end());  
  // a copy of third
  vector<int> fourth(third);        
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16, 2, 77, 29};
  vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
  cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    cout << ' ' << *it;
  cout << endl;
  return 0;
}
