#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 t, p, r, f;
    cin >> t;
    for(i64 i = 0; i < t; i++){
        cin >> p >> r >> f;
        i64 y = 0;
        while(true){
            if(f / p > 0){
                y++;
                p *= r;
            }
            else{
                break;
            }
        }
        cout << y << endl;
    }
    return 0;
}
