#include <boost/intrusive/list.hpp>
#include <string>
#include <utility>
#include <iostream>

using namespace std;
using namespace boost::intrusive;

struct animal : public list_base_hook<>
{
  string name;
  int legs;
  animal(string n, int l) : name{move(n)}, legs{l} {}
};

int main()
{
  animal a1{"cat", 4};
  animal a2{"shark", 0};
  animal a3{"spider", 8};

  typedef list<animal> animal_list;
  animal_list animals;

  animals.push_back(a1);
  animals.push_back(a2);
  animals.push_back(a3);

  a1.name = "dog";

  for (const animal &a : animals)
    cout << a.name << " ";
  cout << endl;
}
