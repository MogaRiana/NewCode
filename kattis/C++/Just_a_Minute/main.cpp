#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 n;
    d64 ds = 0, dm = 0;
    cin >> n;
    v m(n);
    v s(n);
    for(i64 i = 0; i < n; i++) {
        cin >> m[i] >> s[i];
        m[i] = m[i] * 60;
        dm += m[i];
        ds += s[i];
    }
    d64 avl = ds / dm;
    if(avl <= 1) {
        cout << "measurement error" << endl;
    }
    else {
        cout.precision(9);
        cout << fixed << avl;
    }
    return 0;
}
