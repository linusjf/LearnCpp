#include <iostream>

using namespace std;

enum class new_enum : unsigned int {
  value1,
  value2,
  value3 = 100,
  value4 = 100

};

template <typename T>
ostream& operator<<(
    typename enable_if<is_enum<T>::value, ostream>::type& stream,
    const T& e) {
  return stream << static_cast<typename underlying_type<T>::type>(e);
}

int main() {
  if (new_enum::value3 == new_enum::value4) {
    cout << "new_enum::value3 == new_enum::value4" << endl;
  }
  cout << new_enum::value3 << endl;
}
