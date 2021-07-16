#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

// Implement << for pairs: this is needed to print out mappings where range
// iteration goes over (key, value) pairs.
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

template <template <typename, typename...> class ContainerType,
          typename ValueType,
          typename... Args>
void print_container(const ContainerType<ValueType, Args...>& c) {
  for (const auto& v: c)
    cout << v << ' ';
  cout << endl;
}

int main() {
  vector<double> vd{3.14, 8.1, 3.2, 1.0};
  print_container(vd);

  list<int> li{1, 2, 3, 5};
  print_container(li);

  map<string, int> msi{{"foo", 42}, {"bar", 81}, {"bazzo", 4}};
  print_container(msi);
}
