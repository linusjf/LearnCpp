#include <iostream>

using namespace std;

class Time {
 private:
  // 0 to 23
  int hours;  
  // 0 to 59
  int minutes; 
  void increment() {
    ++minutes;  
    if (minutes >= 60) {
      ++hours;
      minutes -= 60;
    }
    if (hours >= 24) {
      hours -= 24;
    }
  }
 
 public:
  Time() {
    hours = 0;
    minutes = 0;
  }
  
  Time(int h, int m) {
    hours = h;
    minutes = m;
  }

  // method to display time
  void displayTime() {
    cout << "H: " << hours << " M:" << minutes << endl;
  }
 
  // overloaded prefix ++ operator
  Time operator++() {
    increment();
    return Time(hours, minutes);
  }

  // overloaded postfix ++ operator
  Time operator++(int) {
    Time T(hours, minutes);
    increment();
    return T;
  }
};

int main() {
  Time T1(11, 59), T2(10, 40), T3(23,59), T4(26,00);
  ++T1;              
  T1.displayTime();  
  ++T1;              
  T1.displayTime(); 
  T2++;             
  T2.displayTime();  
  T2++;              
  T2.displayTime();  
  T3++;             
  T3.displayTime();  
  T3++;              
  T3.displayTime();  
  T4++;             
  T4.displayTime();  
  T4++;              
  T4.displayTime();  
  return 0;
}
