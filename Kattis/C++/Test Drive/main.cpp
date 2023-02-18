#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(abs(b - a) == abs(c - b))
    {
        cout << "cruised" << endl;
    }
    else if((a < b && b > c) || (a > b && b < c))
    {
        cout << "turned" << endl;
    }
    else if(abs(a - b) < abs(c - b))
    {
        cout << "accelerated" << endl;
    }
     else
    {
        cout << "braked" <<  endl;
    }
    return 0;
}
