#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<d64> vd64;
typedef vector<vi64> vv;

int main()
{
    i64 m, s;
    cin >> m >> s;
    vv p(m, vector<i64> (s));
    for(i64 i = 0; i < m; i++){
        for(i64 j = 0; j < s; j++){
            cin >> p[i][j];
        }
    }
    vi64 a(m);
    for(i64 i = 0; i < m; i++){
        a[i] = p[i][0];
    }
    set<i64> b;
    for(i64 i = 0; i < m; i++){
        b.insert(a[i]);
        for(i64 j = 0; j < m; j++){
            for(i64 k = 0; k < s; k++){
                if(p[j][k] != a[i]){
                    b.insert(p[j][k]);
                }
                else{
                    break;
                }
            }
        }
    }
    vi64 c(b.begin(), b.end());
    sort(c.begin(), c.end());
    cout << c.size() << endl;
    for(i64 i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    return 0;
}
