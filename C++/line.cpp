#include <iostream>

using namespace std;

class Line {
 public:
  Line();
  Line(double len);
  Line(const Line& line);
  ~Line();
  void setLength(double len);
  double getLength(void);

 protected:
  double* length;
};

Line::Line(void) : Line(0.0) {
}

Line::Line(double len) {
  length = new double;
  *length = len;
}

Line::Line(const Line& obj) : Line(*obj.length) {
}

Line::~Line() {
  delete length;
}

double Line::getLength(void) {
  return *length;
}

void Line::setLength(double len) {
  *length = len;
}

void display(Line obj) {
  cout << "Length of line : " << obj.getLength() << endl;
}

int main() {
  Line line;
  // set line length
  line.setLength(6.0);
  display(line);
  Line line2(10);
  display(line2);
  // This also calls copy constructor
  Line line3 = line;
  display(line3);
  return 0;
}
