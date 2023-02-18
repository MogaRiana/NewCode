#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
    i64 n;
    while(cin >> n) {
        v64 v(n);
        vector<bool> a(n,false);
        for(i64 i = 0; i < n; i++) {
            cin >> v[i];
        }
        for(i64 i = 0; i < n - 1; i++) {
            i64 b = abs(v[i] - v[i + 1]);
            if(b < n) {
                a[b] = true;
            }
        }
        bool ok = true;
        for(i64 i = 1; i < n; i++) {
            if(!a[i]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}
