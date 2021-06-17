#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <bool T>
class MajicType {
  bool magic = T;
};

// legal, but not recommended
vector<MajicType<(1 > 2)>> majic;

template <typename T, typename U>
class MagicType {
 public:
  T dark;
  U magic;
};

template <typename T>
using TrueDarkMagic = MagicType<vector<T>, string>;

typedef int (*process)(void *);
using NewProcess = int (*)(void *);

template <typename T, typename U>
auto addx(T x, U y) -> decltype(x + y) {
  return x + y;
}

template <typename T = int, typename U = int>
auto addy(T x, U y) -> decltype(x + y) {
  return x + y;
}

template<class T, class U = int> class A;
template<class T = float, class U> class A;

template<class T, class U> class A {
   public:
      T x;
      U y;
};

template<class T = int> class A1;
template<class T = float> class B;
template<class V, V obj> class C;
// a template parameter (T) used as the default argument
// to another template parameter (U)
template<class T, class U = T> class D { };

int main() {
  TrueDarkMagic<bool> you;
  cout << addy(2,3) << endl;
  A<> a;
  a.x = 10;
  a.y = 13;
  cout << addx<int,int>(a.x,a.y) << endl;
}
