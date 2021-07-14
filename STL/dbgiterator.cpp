#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3};
  v.shrink_to_fit();
  const auto it(begin(v));
  cout << *it << endl;
  v.push_back(123);
  // bad bad bad!
  cout << *it << endl;  
}
