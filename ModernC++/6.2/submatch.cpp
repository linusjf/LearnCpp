#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
  regex base_regex("([a-z]+)\\.txt");
  smatch base_match;
  for (const auto &fname: fnames) {
    if (regex_match(fname, base_match, base_regex)) {
      // the first element of smatch matches the entire string
      // the second element of smatch matches the first expression with brackets
      if (base_match.size() == 2) {
        string base = base_match[1].str();
        cout << fname << ": " << endl;
        cout << "sub-match[0]: " << base_match[0].str() << endl;
        cout << "sub-match[1]: " << base << endl;
      }
    }
  }
}
