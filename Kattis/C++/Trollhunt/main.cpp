#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int b, k, g;
    cin >> b >> k >> g;
    int t = k / g;
    cout << ceil(double(b - 1) / t) << endl;
    return 0;
}
