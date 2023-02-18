#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 t, d, m;
    cin >> t;
    for (i64 i = 0; i < t; i++) {
        cin >> d >> m;
        i64 arr[m];
        for (i64 j = 0; j < m; j++) {
            cin >> arr[j];
        }
        i64 crt = 0, day = 7, fday = 1;
        for (i64 k = 0; k < m; k++) {
            for (i64 g = 1; g <= arr[k]; g++) {
                if (day == 5 && g == 13) {
                    crt++;
                }
                day++;
                if (day == 8) {
                    day = 1;
                }
            }
        }
        cout << crt << endl;
    }
    return 0;
}