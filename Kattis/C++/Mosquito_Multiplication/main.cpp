#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 m, p, l, e, r, s, n;
    while(cin >> m >> p >> l >> e >> r >> s >> n) {
        i64 sum = 0, a, b, c;
        for(i64 i = 0; i < n; i++) {
            m *= e;
            i += 1;
            m /= r;
            i += 1;
            m /= s;
            i += 2;
        }
        sum += m;
        for(i64 i = 0; i < n; i++) {
            p /= s;
            i += 3;
            p *= e;
            i += 1;
            p /= r;
            b = i + 1;
        }
        if(b < n) {
            p /= s;
            sum += p;
        }
        for(i64 i = 0; i < n; i++) {
            l /= r;
            i += 1;
            l /= s;
            i += 3;
            l *= e;
            i += 1;
            c = i + 1;
        }
        if(c < n) {
            sum += l;
        }
        cout << sum << endl;
    }
    return 0;
}
