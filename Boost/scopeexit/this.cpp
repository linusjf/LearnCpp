#include <boost/scope_exit.hpp>
#include <iostream>

using namespace std;

struct x {
  int i;

  void foo() {
    i = 10;
    BOOST_SCOPE_EXIT(void) {
      cout << "last\n";
    }
    BOOST_SCOPE_EXIT_END
    BOOST_SCOPE_EXIT(this_) {
      this_->i = 20;
      cout << "first\n";
    }
    BOOST_SCOPE_EXIT_END
  }
};

int main() {
  x obj;
  obj.foo();
  cout << obj.i << endl;
}
