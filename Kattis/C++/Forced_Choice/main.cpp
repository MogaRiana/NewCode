#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 n, p, s;
    cin >> n >> p >> s;
    v c(n);
    for(i64 i = 0; i < n; i++){
        c[i] = i + 1;
    }
    for(i64 i = 0; i < s; i++){
        i64 t;
        cin >> t;
        v cc(t);
        for(i64 i = 0; i < t; i++){
            cin >> cc[i];
        }
        bool a = false;
        for(i64 i = 0; i < t; i++){
            if(cc[i] == p){
                a = true;
                break;
            }
            else{
                a = false;
            }
        }
        if(a){
            cout << "KEEP" << endl;
        }
        else{
            cout << "REMOVE" << endl;
        }
    }
    return 0;
}
