#include <iostream>

using namespace std;

int main()
{
    int n;
    double q, y, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> q >> y;
        s += q * y;
    }
    cout.precision(3);
    cout << fixed << s;
    return 0;
}
