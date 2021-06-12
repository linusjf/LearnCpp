#include <iostream>

#include "Box.cpp"

using namespace std;

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
