#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 a, b, s;
    bool c = true;
    cin >> a >> b >> s;
    for(i64 i = 1; i <= s; i++){
        if(i % a == 0 && i % b == 0){
            cout << "yes" << endl;
            c = false;
            break;
        }
    }
    if(c){
        cout << "no" << endl;
    }
    return 0;
}
