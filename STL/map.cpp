#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<char, int> letter_counts{{'a', 27}, {'b', 3}, {'c', 1}};

  cout << "initially:\n";
  for (const auto &pair: letter_counts) 
    cout << pair.first << ": " << pair.second << endl;

  // update an existing value
  letter_counts['b'] = 42;  
  // insert a new value
  letter_counts['x'] = 9;   

  cout << "after modifications:\n";
  for (const auto &pair: letter_counts) 
    cout << pair.first << ": " << pair.second << endl;

  // count the number of occurrences of each word
  // (the first call to operator[] initialized the counter with zero)
  map<string, size_t> word_map;
  for (const auto &w: {"this",
                       "sentence",
                       "is",
                       "not",
                       "a",
                       "sentence",
                       "this",
                       "sentence",
                       "is",
                       "a",
                       "hoax"}) {
    ++word_map[w];
  }

  for (const auto &[word, count]: word_map) 
    cout << count << " occurrences of word '" << word << "'\n";
}
