#include <iostream>

using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    if (r == 0 && l == 0)
    {
        cout << "Not a moose";
    }
    else if (l == r)
    {
        cout << "Even " << l + r << endl;
    }
    else if (l != r && r <= l || l <=r)
    {
        if (l > r)
        {
            cout << "Odd " << 2*l;
        }
        else if (r > l)
        {
            cout << "Odd " << 2*r;
        }
    }
    return 0;
}
