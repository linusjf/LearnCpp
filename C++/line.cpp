#include <iostream>

using namespace std;

class Line {
 public:
  Line();
  Line(double len);
  ~Line();
  void setLength(double len);
  double getLength(void);

 protected:
  double length;
};

Line::Line(void) {
  length = 0;
}

Line::Line(double len) : length(len) {
}

Line::~Line() {
}

double Line::getLength(void) {
  return length;
}

void Line::setLength(double len) {
  length = len;
}

int main() {
  Line line;
  // set line length
  line.setLength(6.0);
  cout << "Length of line : " << line.getLength() << endl;
  return 0;
}
