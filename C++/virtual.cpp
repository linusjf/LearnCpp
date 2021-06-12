#include <iostream>

using namespace std;

class Shape {
 public:
  Shape() {
  }

  virtual int area() = 0;
};

class Rectangle : public Shape {
 protected:
  int height, width;

 public:
  Rectangle(int a = 0, int b = 0) : Shape() {
    width = a;
    height = b;
  }

  int area() {
    return (width * height);
  }
};

class Triangle : public Shape {
 protected:
  int height, width;

 public:
  Triangle(int a = 0, int b = 0) : Shape() {
    width = a;
    height = b;
  }
 
  int area() {
    return (width * height / 2);
  }
};

int main() {
  Shape *shape;
  Rectangle rec(10, 7);
  Triangle tri(10, 5);
  shape = &rec;
  cout << "Rectangle area: " << shape->area() << endl;
  shape = &tri;
  cout << "Triangle area: " << shape->area() << endl;
  return 0;
}
