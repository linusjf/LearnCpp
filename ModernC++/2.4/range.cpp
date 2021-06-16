#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec = {1, 2, 3, 4};
  if (auto itr = find(vec.begin(), vec.end(), 3); itr != vec.end())
    *itr = 4;
  // read only
  for (auto element: vec)
    cout << element << " ";
  cout << endl;  
  // writeable
  for (auto &element: vec) {
    element += 1;  
  }
  // read only
  for (auto element: vec)
    cout << element << " ";
  cout << endl;  
}
