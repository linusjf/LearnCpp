#include <iostream>
using namespace std;
int boxMain();

class Box {
 public:
  inline static int objectCount = 0;

  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    length = l;
    breadth = b;
    height = h;
    // Increase every time object is created
    objectCount++;
  }

  double getVolume() {
    return length * breadth * height;
  }

  void setLength(double len) {
    length = len;
  }

  void setBreadth(double bre) {
    breadth = bre;
  }
  
  void setHeight(double hei) {
    height = hei;
  }

  int compare(Box box) {
    return this->getVolume() > box.getVolume();
  }

  // Overload + operator to add two Box objects.
  Box operator+(const Box& b) {
    Box box;
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
  }

  static int getCount() {
    return objectCount;
  }

  friend void printWidth( Box box ) {
 cout << "Width of box : " << box.breadth <<endl;
  }

 protected:
  // Length of a box
  double length;
  // Breadth of a box
  double breadth;
  // Height of a box
  double height;
};


