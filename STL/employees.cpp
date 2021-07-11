#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct employee {
  unsigned id;
  string name;
  string role;
  unsigned salary;
  employee(int id, string name, string role, int sal) {
    this->id = id;
    this->name = name;
    this->role = role;
    this->salary = sal;
  }
};

int main() {
  vector<employee> employees{
      employee(1, "Jake", "Manager", 21000),
      employee(2, "Jonas", "Foreman", 34567),
  };
  for (const auto &[id, name, role, salary]: employees) {
    cout << "Name: " << name << " Role: " << role << " Salary: " << salary
         << '\n';
  }
}
