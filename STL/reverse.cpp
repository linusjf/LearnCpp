#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
  list<int> l{1, 2, 3, 4, 5};
  copy(l.begin(), l.end(), ostream_iterator<int>{cout, ", "});
  cout << endl;
  copy(l.rbegin(), l.rend(), ostream_iterator<int>{cout, ", "});
  cout << endl;
  copy(make_reverse_iterator(end(l)),
       make_reverse_iterator(begin(l)),
       ostream_iterator<int>{cout, ", "});
  cout << endl;
}
