#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a = m - n;
    if(a == 1)
    {
        cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
    }
    else if(a > 0)
    {
        cout << "Dr. Chaz will have " << a << " pieces of chicken left over!" << endl;
    }
    else if(a == -1)
    {
        cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
    }
    else
    {
        cout << "Dr. Chaz needs " << a * (-1) << " more pieces of chicken!" << endl;
    }
    return 0;
}
