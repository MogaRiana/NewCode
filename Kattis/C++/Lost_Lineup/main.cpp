#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    cin >> n;
    i64 m = n - 1;
    i64 d[m];
    for(i64 i = 0; i < m; i++) {
        cin >> d[i];
    }
    cout << 1 << " ";
    i64 s = 0, a = m;
    while(a > 0) {
        for(i64 i = 0; i < m; i++) {
            if(d[i] == s) {
                cout << i + 2 << " ";
                s++;
            }
        }
        a--;
    }
    return 0;
}
