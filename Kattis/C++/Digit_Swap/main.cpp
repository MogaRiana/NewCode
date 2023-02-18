#include <iostream>

using namespace std;

int main()
{
    int n, nr, a, b;
    cin >> n;
    a = n % 10;
    b = n / 10;
    nr = a * 10 + b;
    cout << nr;
    return 0;
}
