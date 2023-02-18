#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n, t;
    cin >> n;
    for(i64 i = 0; i < n; i++) {
        cin >> t;
        i64 g[t];
        cin >> g[0];
        for(i64 j = 1; j < t; j++) {
            cin >> g[j];
        }
        for(i64 k = 1; k < t; k++) {
            if(g[k] - 1 != g[k - 1]) {
                cout << k + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
