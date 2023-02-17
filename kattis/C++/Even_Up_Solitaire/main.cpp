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
    vi64 v(n);
    vi64 a;
    i64 b = a.size();
    for(i64 i = 0; i < n; i++) {
        cin >> v[i];
    }
    while(true) {
        for(i64 i = 0; i < v.size(); i++) {
            if((v[i] + v[i+1]) % 2 == 0 && i != v.size() - 1) {
                i++;
            }
            else{
                a.push_back(v[i]);
            }
        }
        if(b == a.size()){
            break;
        }
        b = a.size();
        v = a;
        a.clear();
    }
    cout << b << endl;
    return 0;
}
