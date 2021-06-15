#include <iostream>

using namespace std;

int main ()
{
 cout << "Set-Cookie:UserID=XYZ;";
 cout << "Set-Cookie:Password=XYZ123;";
 cout << "Set-Cookie:Domain=www.tutorialspoint.com;";
 cout << "Set-Cookie:Path=/perl;";
 cout << "Content-type:text/html\r\n\r\n";
 cout << "<html>\n";
 cout << "<head>\n";
 cout << "<title>Cookies in CGI</title>\n";
 cout << "</head>\n";
 cout << "<body>\n";
 cout << "Setting cookies" << endl; 
 cout << "<br/>\n";
 cout << "</body>\n";
 cout << "</html>";
 return 0;
}
