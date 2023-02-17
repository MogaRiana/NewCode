#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vector<i64>> vv;

int main()
{
    i64 n;
    cin >> n;
    vector<string> x(n);
    for(i64 i = 0; i < n; i++){
        cin >> x[i];
    }
    for(i64 i = 0; i < n; i+= 2){
        cout << x[i] << endl;
    }
    return 0;
}
