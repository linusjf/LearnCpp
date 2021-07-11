#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, size_t> animal_population{
      {"humans", 7000000000},
      {"chickens", 17863376000},
      {"camels", 24246291},
      {"sheep", 1086881528},
  };

  for (const auto &[species, count]: animal_population) {
    cout << "There are " << count << " " << species
              << " on this planet.\n";
  }
}
