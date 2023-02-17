#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<v> vv;

int main()
{
    i64 t, sum = 20, c, x = 4, crt = 0;
    bool a = true;
    cin >> t;
    v y(t);
    for(i64 i = 0; i < t; i++) {
        cin >> y[i];
    }
    for(i64 i = 0; i < min(x, t); i++) {
        crt += y[i];
        if(crt >= 10) {
            x = i + 5;
            crt = 0;
        }
        sum += y[i];
        if(sum >= 100) {
            cout << "Touchdown" << endl;
            a = false;
            break;
        }
        else if(sum <= 0) {
            cout << "Safety" << endl;
            a = false;
            break;
        }
    }
    if(a) {
        cout << "Nothing" << endl;
    }
    return 0;
}
