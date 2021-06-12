#include <iostream>

using namespace std;

class Distance {
 private:
  int feet;
  int inches;

 public:
  Distance() {
    feet = 0;
    inches = 0;
  }

  Distance(int f, int i) {
    feet = f;
    inches = i;
  }

  Distance(const Distance &obj) : Distance(obj.feet, obj.inches) {
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

  void operator=(const Distance &D) {
    feet = D.feet;
    inches = D.inches;
  }

  // overloaded minus (-) operator
  Distance operator-() {
    return Distance(-feet, -inches);
  }

  // overload function call
  Distance operator()(int a, int b, int c) {
    Distance D;
    D.feet = a + c + 10;
    D.inches = b + c + 100;
    return D;
  }

  ~Distance() {
  }
};

int main() {
  Distance D1(11, 10), D2(-5, 11), D3;
  D1 = -D1;
  D1.displayDistance();
  Distance D4 = -D2;
  D2.displayDistance();
  D4.displayDistance();

  cout << "Enter the value of object : " << endl;
  cin >> D3;
  cout << "First Distance : " << D1 << endl;
  cout << "Second Distance :" << D2 << endl;
  cout << "Third Distance :" << D3 << endl;
  D1 = D2;
  cout << "First Distance :";
  D1.displayDistance();
  // invoke operator()
  D2 = D1(10, 10, 10);
  cout << "Second Distance :";
  D2.displayDistance();
  return 0;
}
