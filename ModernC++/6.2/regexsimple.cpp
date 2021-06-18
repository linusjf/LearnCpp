#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
  // In C++, `\` will be used as an escape character in the string. In order for `\.` to be passed as a regular expression, it is necessary to perform second escaping of `\`, thus we have `\\.`
  regex txt_regex("[a-z]+\\.txt");
  for (const auto &fname: fnames)
    cout << fname << ": " << regex_match(fname, txt_regex)
              << " ";
  cout << endl;
}
