#include <iostream>

using namespace std;

class Box {
 public:
  // Constructor definition
  Box(double l = 2.0, double b = 2.0, double h = 2.0) {
    cout << "Constructor called." << endl;
    length = l;
    breadth = b;
    height = h;
  }

  double Volume() {
    return length * breadth * height;
  }
  
  int compare(Box box) {
    return this->Volume() > box.Volume();
  }

 private:
  // Length of a box
  double length;   
  // Breadth of a box
  double breadth;  
  // Height of a box
  double height;   
};

int main(void) {
  // Declare box1
  Box Box1(3.3, 1.2, 1.5);  
  // Declare box2
  Box Box2(8.5, 6.0, 2.0);  
  if (Box1.compare(Box2)) 
    cout << "Box2 is smaller than Box1" << endl;
   else 
    cout << "Box2 is equal to or larger than Box1" << endl;
  return 0;
}
