#include <fstream>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>

using namespace std;

void WriteToFile(const string& message) {
  // |mutex| is to protect access to |file| (which is shared across threads).
  static mutex _mutex;

  // Lock |mutex| before accessing |file|.
  lock_guard<mutex> lock(_mutex);

  // Try to open file.
  ofstream file("example.txt");
  if (!file.is_open()) {
    throw runtime_error("unable to open file");
  }

  // Write |message| to |file|.
  file << message << endl;

  // |file| will be closed first when leaving scope (regardless of exception)
  // mutex will be unlocked second (from lock destructor) when leaving scope
  // (regardless of exception).
}

int main() {
  WriteToFile("Test message");
}
