#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 n, l, d, r, g, t = 0;
    cin >> n >> l;
    cin >> d >> r >> g;
    if(r > d){
        t += r - d;
    }
    i64 d2 = d, r2 = r, g2 = g;
    for(i64 i = 0; i < n - 1; i++){
        cin >> d >> r >> g;
        if(r > d){
            t += r - d;
        }
        else{
            r -= d - d2;
            t += r;
        }
    }
    cout << l + t;
    return 0;
}
