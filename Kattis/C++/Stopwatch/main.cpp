#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    i64 n;
    cin >> n;
    vi64 v(n);
    for(i64 i = 0; i < n; i++){
        cin >> v[i];
    }
    if(n % 2 != 0){
        cout << "still running" << endl;
        return 0;
    }
    i64 crt = 0;
    for(i64 i = 1; i < n; i += 2){
        crt += v[i] - v[i - 1];
    }
    cout << crt << endl;
    return 0;
}
