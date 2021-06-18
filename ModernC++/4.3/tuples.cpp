#include <iostream>
#include <tuple>
#include <variant>
using namespace std;

template <size_t n, typename... T>
constexpr variant<T...> _tuple_index(const tuple<T...>& tpl, size_t i) {
  if constexpr (n >= sizeof...(T))
    throw out_of_range(" .");
  if (i == n)
    return variant<T...>{in_place_index<n>, get<n>(tpl)};
  return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)>(tpl, i);
}

template <typename... T>
constexpr variant<T...> tuple_index(const tuple<T...>& tpl, size_t i) {
  return _tuple_index<0>(tpl, i);
}

template <typename T0, typename... Ts>
ostream& operator<<(ostream& s, variant<T0, Ts...> const& v) {
  visit([&](auto&& x) { s << x; }, v);
  return s;
}

template <typename T>
auto tuple_len(T& __unused tpl) {
  return tuple_size<T>::value;
}

auto get_student(int id) {
  if (id == 0)
    return make_tuple(3.8, 'A', "John");
  if (id == 1)
    return make_tuple(2.9, 'C', "Jack");
  if (id == 2)
    return make_tuple(1.7, 'D', "Ive");
  // it is not allowed to return 0 directly
  // return type is tuple<double, char, string>
  return make_tuple(0.0, 'D', "null");
}

int main() {
  auto student = get_student(0);
  cout << "ID: 0, "
       << "GPA: " << get<0>(student) << ", "
       << "Grade: " << get<1>(student) << ", "
       << "Name: " << get<2>(student) << '\n';
  double gpa;
  char grade;
  string name;
  // unpack tuples
  tie(gpa, grade, name) = get_student(1);
  cout << "ID: 1, "
       << "GPA: " << gpa << ", "
       << "Grade: " << grade << ", "
       << "Name: " << name << '\n';
  tuple<string, double, double, int> t("123", 4.5, 6.7, 8);
  cout << get<string>(t) << endl;
  cout << get<3>(t) << endl;
  int i = 1;
  cout << tuple_index(t, i) << endl;
  auto new_tuple = tuple_cat(get_student(1), move(t));
  for (unsigned long i = 0; i != tuple_len(new_tuple); ++i)
    // runtime indexing
    cout << tuple_index(new_tuple, i) << " ";
  cout << endl;
}
