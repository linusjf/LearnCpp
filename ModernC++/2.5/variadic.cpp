#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename... Ts>
class Magic {};

class Magic<int, vector<int>, map<string, vector<int>>> darkMagic;

template <typename Require, typename... Args>
class MagicNext;

template <typename... Args>
void printf(const string &str, Args... args);

template <typename... Ts>
void magic(Ts... args) {
  cout << sizeof...(args) << endl;
}

int main() {
  magic();
  magic(1);
  magic(1, "");
}
