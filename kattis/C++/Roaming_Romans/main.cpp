#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    long double n;
    cin >> n;
    i64 res =  round((n * 1000 * 5280) / 4854.0);
    cout << res;
    return 0;
}
