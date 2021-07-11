#include <vector>

using namespace std;

int main() {
[[maybe_unused]] int x1 = 1;
[[maybe_unused]] int x2 {1};
[[maybe_unused]] int x3 (1);
// Vector with three ints: 1, 2, 3
[[maybe_unused]] vector<int> v1 {1, 2, 3}; 
// same here
[[maybe_unused]] vector<int> v2 = {1, 2, 3}; 
// Vector with 10 ints,
[[maybe_unused]] vector<int> v3 (10, 20);

// v is int
[[maybe_unused]] auto v {1}; 
// error: only single elements in direct
// auto w {1, 2}; 
// auto initialization allowed! (this is new)
// x is initializer_list<int>
[[maybe_unused]] auto x = {1}; 
// y is initializer_list<int>
[[maybe_unused]] auto y = {1, 2}; 
// error: Cannot deduce element type
// auto z = {1, 2, 3.0}; 
}
