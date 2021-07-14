#include <ranges>
#include <iostream>

using namespace std;

int main()
{
    auto const ints = {0,1,2,3,4,5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    // "pipe" syntax of composing the views:
    for (int i : ints | views::filter(even) | views::transform(square)) {
        cout << i << ' ';
    }
 
    cout << endl;
 
    // a traditional "functional" composing syntax:
    for (int i : views::transform(views::filter(ints, even), square)) {
        cout << i << ' ';
    }
}
