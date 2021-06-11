#include <iostream>

using namespace std;

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

  double Volume() {
    return length * breadth * height;
  }

  int compare(Box box) {
    return this->Volume() > box.Volume();
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
  Box *ptrBox;
  // Save the address of first object
  ptrBox = &Box1;
  // Now try to access a member using member access operator
  cout << "Volume of Box1: " << ptrBox->Volume() << endl;
  // Save the address of first object
  ptrBox = &Box2;
  // Now try to access a member using member access operator
  cout << "Volume of Box2: " << ptrBox->Volume() << endl;
  if (Box1.compare(Box2))
    cout << "Box2 is smaller than Box1" << endl;
  else
    cout << "Box2 is equal to or larger than Box1" << endl;
  // Print total number of objects after creating object.
  cout << "Final Stage Count: " << Box::getCount() << endl;
  return 0;
}
