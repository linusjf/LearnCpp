#include <iostream>

using namespace std;

class Shape {
 public:
  void setWidth(int w) {
    width = w;
  }
  void setHeight(int h) {
    height = h;
  }

 protected:
  int width;
  int height;
};
