#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    string in = "abcdefghijklmnopqrstuvwxyz", out;
    sample(in.begin(), in.end(), back_inserter(out),
                5, mt19937{random_device{}()});
    cout << "five random letters out of " << in << " : " << out << endl;
}
