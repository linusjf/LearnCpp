#include <iostream>
#include "Box.cpp"

using namespace std;

class SmallBox:Box
{
 public:
 void setSmallWidth( double wid );
 double getSmallWidth( void );
};

// Member functions of child class
double SmallBox::getSmallWidth(void)
{
 return this->breadth ;
}

void SmallBox::setSmallWidth( double wid )
{
 this->breadth = wid;
}

// Main function for the program
int main( )
{
  SmallBox box;
 // set box width using member function
 box.setSmallWidth(5.0);
 cout << "Width of box : "<< box.getSmallWidth() << endl;
 return 0;
}
