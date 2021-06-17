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

int main() {
  TrueDarkMagic<bool> you;
}
