#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    double r, m, c;
    while(cin >> r >> m >> c){
        if(r == 0 && m == 0 && c == 0){
            return 0;
        }
        cout.precision(5);
        cout << fixed << r * r * 3.14159265 << " " << c / m * 4 * r * r << endl;
    }
    return 0;
}
