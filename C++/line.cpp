#include <iostream>

using namespace std;

class Line {
 public:
  void setLength(double len);
  double getLength(void);
 
 protected:
  double length;
};

// Member functions definitions
double Line::getLength(void) {
  return length;
}

void Line::setLength(double len) {
  length = len;
}

// Main function for the program
int main() {
  Line line;
  // set line length
  line.setLength(6.0);
  cout << "Length of line : " << line.getLength() << endl;
  return 0;
}
