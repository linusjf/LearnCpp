#include "paintcost.cpp"
#include "shape.cpp"

class Rectangle : public Shape, public PaintCost {
 public:
  int getArea() {
    return (width * height);
  }
};

int main(void) {
  Rectangle Rect;
  Rect.setWidth(5);
  Rect.setHeight(7);
  int area = Rect.getArea();
  // Print the area of the object.
  cout << "Total area: " << Rect.getArea() << endl;
  // Print the total cost of painting
  cout << "Total paint cost: $" << Rect.getCost(area) << endl;
  return 0;
}
