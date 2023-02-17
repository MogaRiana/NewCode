#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a;
    cin >> a;
    double f = 4 * sqrt(a);
    cout.precision(18);
    cout << fixed;
    cout << f;
    return 0;
}
