#include <iostream>
#include <string>
using namespace std;

int main() {
  struct name_greeter {
    string name;
    void operator()() {
      cout << "Hello, " << name << '\n';
    }
  };
  name_greeter greet_john_doe{"John Doe"};
  greet_john_doe();
}
