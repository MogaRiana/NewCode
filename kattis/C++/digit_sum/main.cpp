#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    cin >> n;
    for(i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        i64 sum = 0;
        for(i64 j = a; j <= b; j++) {
            i64 c = j;
            while(c) {
                sum += c % 10;
                c /= 10;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
