#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 r, n;
    cin >> r >> n;
    vector<i64> m(n);
    for(i64 i = 0; i < n; i++) {
        cin >> m[i];
    }
    if(r == n) {
        cout << "too late";
    }
    else {
        i64 a = 0;
        sort(m.begin(), m.end());
        for(i64 i = 1; i <= r; i++) {
            for(i64 j = 0; j < n; j++) {
                if(i == m[j]) {
                    a = i;
                    break;
                }
            }
            if(i != a) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}
