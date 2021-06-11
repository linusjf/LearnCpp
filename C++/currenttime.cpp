#include <ctime>
#include <iostream>

using namespace std;

int main() {
  // current date/time based on current system
  time_t now = time(0);

  // convert now to string form
  char *dt = ctime(&now);
  cout << "The local date and time is: " << dt << endl;
  // convert now to tm struct for UTC
  tm *gmtm = gmtime(&now);
  dt = asctime(gmtm);
  cout << "The UTC date and time is: " << dt << endl;

  // current date/time based on current system
  now = time(0);
  cout << "Number of seconds since January 1,1970: " << now << endl;
  tm *ltm = localtime(&now);
  // print various components of tm structure.
  cout << "Year: " << 1900 + ltm->tm_year << endl;
  char val[3];
  sprintf(val,"%02d",1 + ltm->tm_mon);
  cout << "Month: " << val << endl;
  sprintf(val,"%02d",ltm->tm_mday);
  cout << "Day: " << val << endl;
  sprintf(val,"%02d",1 + ltm->tm_hour);
  cout << "Time: " << val << ":";
  sprintf(val,"%02d",1 + ltm->tm_min);
  cout << val << ":";
  sprintf(val,"%02d",1 + ltm->tm_sec);
  cout << val  << endl;
}
