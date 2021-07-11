#include <iostream>
using namespace std;

int main(int __attribute__((unused)) _, char *argv[]) {
  char szChEntered[] = "Character entered was: ";
  switch (tolower(*argv[1])) {

    case 'a':
      cout << szChEntered << "a\n";
      break;

    case 'b':
      // Value of szChEntered undefined.
      cout << szChEntered << "b\n";
      break;

    default:
      // Value of szChEntered undefined.
      cout << szChEntered << "neither a nor b\n";
      break;
  }
}
