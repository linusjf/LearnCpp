#include <iostream>

using namespace std;

void may_throw() {
  throw true;
}

auto non_block_throw = [] { may_throw(); };

void no_throw() noexcept {
  return;
}

auto block_throw = []() noexcept { no_throw(); };

int main() {
  cout << boolalpha << "may_throw() noexcept? " << noexcept(may_throw()) << endl
       << "no_throw() noexcept? " << noexcept(no_throw()) << endl
       << "lmay_throw() noexcept? " << noexcept(non_block_throw()) << endl
       << "lno_throw() noexcept? " << noexcept(block_throw()) << endl;
  try {
    may_throw();
  } catch (...) {
    cout << "exception captured from may_throw()" << endl;
  }
  try {
    non_block_throw();
  } catch (...) {
    cout << "exception captured from non_block_throw()" << endl;
  }
  try {
    block_throw();
  } catch (...) {
    cout << "exception captured from block_throw()" << endl;
  }
  return 0;
}
