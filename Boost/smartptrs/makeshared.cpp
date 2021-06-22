#include <boost/make_shared.hpp>
#include <typeinfo>
#include <iostream>
#include <array>

using namespace std;

int main()
{
  auto p1 = make_shared<int>(1);
  cout << typeid(p1).name() << '\n';
  auto p2 = make_shared<array<int, 10>>();
  cout << typeid(p2).name() << '\n';
}
