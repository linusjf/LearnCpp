#include <iostream>

using namespace std;

class Distance {
 private:
  int feet;
  // 0 to infinite
  int inches;
  // 0 to 12
 public:
  // required constructors
  Distance() {
    feet = 0;
    inches = 0;
  }

  Distance(int f, int i) {
    feet = f;
    inches = i;
  }

  // method to display distance
  void displayDistance() {
    cout << "F: " << feet << " I:" << inches << endl;
  }

  friend ostream &operator<<(ostream &output, const Distance &D) {
    output << "F : " << D.feet << " I : " << D.inches;
    return output;
  }

  friend istream &operator>>(istream &input, Distance &D) {
    input >> D.feet >> D.inches;
    return input;
  }

  // overloaded minus (-) operator
  Distance operator-() {
    return Distance(-feet, -inches);
  }
};

int main() {
  Distance D1(11, 10), D2(-5, 11), D3;
  // apply negation
  D1 = -D1;
  // display D1
  D1.displayDistance();
  // apply negation
  Distance D4 = -D2;
  // display D2
  D2.displayDistance();
  D4.displayDistance();

  cout << "Enter the value of object : " << endl;
  cin >> D3;
  cout << "First Distance : " << D1 << endl;
  cout << "Second Distance :" << D2 << endl;
  cout << "Third Distance :" << D3 << endl;
  return 0;
}
