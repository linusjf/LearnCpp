#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>
#include <type_traits>

using namespace std;

int main() {
  array arr = {"lion"sv, "direwolf"sv, "stag"sv, "dragon"sv};
  static_assert(is_same_v<decltype(arr), array<string_view, 4>>);
  sort(arr.begin(), arr.end(), greater{});
  cout << arr.size() << ": ";
  for (const auto& e: arr) 
    cout << e << " ";
  cout << endl;
}
