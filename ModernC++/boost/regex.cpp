#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

int main()
{
    string line;
    regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (cin)
    {
        getline(cin, line);
        smatch matches;
        if (regex_match(line, matches, pat)) {
            cout << matches[0] << endl;
            cout << matches[1] << endl;
            cout << matches[2] << endl;
        }
    }
}
