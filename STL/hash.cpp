#include <cstddef>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

constexpr uint64_t hash_128_to_64(const uint64_t upper,
                                  const uint64_t lower) noexcept {
  // Murmur-inspired hashing.
  const uint64_t kMul = 0x9ddfea08eb382d69ULL;
  uint64_t a = (lower ^ upper) * kMul;
  a ^= (a >> 47);
  uint64_t b = (upper ^ a) * kMul;
  b ^= (b >> 47);
  b *= kMul;
  return b;
}

template <typename T>
size_t hash_combine(const T& t) {
  return hash<T>()(t);
}

template <typename T, typename... Ts>
size_t hash_combine(const T& t, const Ts&... ts) {
  size_t seed = hash<T>()(t);
  if (sizeof...(ts) == 0) {
    return seed;
  }
  size_t remainder = hash_combine(ts...);  // not recursion!
  return hash_128_to_64(seed, remainder);
}

// Simple example
struct Object {
  int x;
  string y;
  float z;

  size_t hash() const {
    return hash_combine(x, y, z);
  }
};

int main() {
  Object obj;
  obj.x = 30;
  obj.y = "hello";
  obj.z = 34.0;
  cout << obj.hash() << endl;

}
