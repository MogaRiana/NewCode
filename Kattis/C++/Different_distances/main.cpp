#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    double x1, y1, x2, y2, p;
    while(cin >> x1 && x1 != 0){
        cin >> y1 >> x2 >> y2 >> p;
        double a = abs(x1 - x2);
        double b = abs(y1 - y2);
        cout.precision(4);
        cout << fixed << pow((pow(a, p) + pow(b, p)), 1/p) << endl;
    }
    return 0;
}
