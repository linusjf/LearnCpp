#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace boost;
using namespace lambda;
using namespace std;

int main()
{
    typedef istream_iterator<int> in;

    for_each(
        in(cin), in(), cout << (_1 * 3) << " " );
}
