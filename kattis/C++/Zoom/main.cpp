#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main()
{
    i64 n, x;
    cin >> n >> x;
    v64 v(n);
    for(i64 i = 0; i < n; i++){
        cin >> v[i];
    }
    for(i64 i = x - 1; i < n; i += x){
        cout << v[i] << " ";
    }
    return 0;
}
