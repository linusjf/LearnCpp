#include <iostream>

using namespace std;

int boxMain();

class Box {
 public:
  static int objectCount;

  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout << "Constructor called." << endl;
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

 private:
  // Length of a box
  double length;
  // Breadth of a box
  double breadth;
  // Height of a box
  double height;
};

// Initialize static member of class Box
int Box::objectCount = 0;

int main(void) {
  // Print total number of objects before creating object.
  cout << "Inital Stage Count: " << Box::getCount() << endl;
  // Declare box1
  Box Box1(3.3, 1.2, 1.5);
  // Declare box2
  Box Box2(8.5, 6.0, 2.0);
  // Declare pointer to a class.
  Box* ptrBox;
  // Save the address of first object
  ptrBox = &Box1;
  // Now try to access a member using member access operator
  cout << "Volume of Box1: " << ptrBox->getVolume() << endl;
  // Save the address of first object
  ptrBox = &Box2;
  // Now try to access a member using member access operator
  cout << "Volume of Box2: " << ptrBox->getVolume() << endl;
  if (Box1.compare(Box2))
    cout << "Box2 is smaller than Box1" << endl;
  else
    cout << "Box2 is equal to or larger than Box1" << endl;
  // Print total number of objects after creating object.
  cout << "Final Stage Count: " << Box::getCount() << endl;
  return boxMain();
}

int boxMain() {
  Box Box1;             // Declare Box1 of type Box
  Box Box2;             // Declare Box2 of type Box
  Box Box3;             // Declare Box3 of type Box
  double volume = 0.0;  // Store the volume of a box here
  // box 1 specification
  Box1.setLength(6.0);
  Box1.setBreadth(7.0);
  Box1.setHeight(5.0);
  // box 2 specification
  Box2.setLength(12.0);
  Box2.setBreadth(13.0);
  Box2.setHeight(10.0);
  // volume of box 1
  volume = Box1.getVolume();
  cout << "Volume of Box1 : " << volume << endl;
  // volume of box 2
  volume = Box2.getVolume();
  cout << "Volume of Box2 : " << volume << endl;
  // Add two object as follows:
  Box3 = Box1 + Box2;
  // volume of box 3
  volume = Box3.getVolume();
  cout << "Volume of Box3 : " << volume << endl;
  return 0;
}
