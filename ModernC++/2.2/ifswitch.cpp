#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec = {1, 2, 3, 4};
  // find finds element with specified value
  const vector<int>::iterator itr = find(vec.begin(), vec.end(), 2);
  if (itr != vec.end()) {
    *itr = 3;
  }
  if (const vector<int>::iterator itr =
          find(vec.begin(), vec.end(), 3);
      itr != vec.end()) {
    *itr = 4;
  }
  // should output: 1, 4, 3, 4. can be simplified using `auto`
  for (auto element = vec.begin(); element != vec.end();
       ++element)
    cout << *element << endl;
}
