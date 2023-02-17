#include <iostream>

using namespace std;

int main()
{
    int r, c, b;
    cin >> r >> c;
    b = r - c;
    double a = r*r * 3.14159;
    double A = b*b * 3.14159;
    cout.precision(6);
    cout << fixed;
    cout << (A / a) * 100;
    return 0;
}
