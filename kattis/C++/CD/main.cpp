#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main()
{
    i64 n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        }
        v64 a(n);
        v64 b(m);
        for(i64 i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(i64 i = 0; i < m; i++) {
            cin >> b[i];
        }
        v64 ans;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
        cout << ans.size() << endl;
    }
    return 0;
}
