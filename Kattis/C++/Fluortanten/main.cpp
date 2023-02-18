#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;


int main()
{
    i64 n, a, m = 0;
    cin >> n;
    vi64 v(n);
    for(i64 i = 0; i < n; i++) {
        cin >> v[i];
        m += v[i] * (i + 1);
        if(v[i] == 0) {
            a = i;
        }
    }
    vi64 x = v;
    for(i64 i = a; i > 0; i--) {
        swap(v[i], v[i - 1]);
        i64 s = 0;
        for(i64 j = 0; j < n; j++) {
            s += v[j] * (j + 1);
        }
        if(s > m) {
            m = s;
        }
    }
    for(i64 i = a + 1; i < n; i++) {
        i64 s = 0;
        swap(x[i], x[i - 1]);
        for(i64 j = 0; j < n; j++) {
            s += x[j] * (j + 1);
        }
        if(s > m) {
            m = s;
        }
    }
    cout << m << endl;
    return 0;
}
