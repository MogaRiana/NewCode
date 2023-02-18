#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<d64> vd64;

int main()
{
    i64 n;
    cin >> n;
    vi64 a(n);
    vi64 b(n);
    for(i64 i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(i64 i = 0; i < n; i++){
        for(i64 j = 1; j < n; j++){
            if(a[i] >  b[j] || b[i] < a[j]){
                cout << "edward is right" << endl;
                return 0;
            }
        }
    }
    cout << "gunilla has a point" << endl;
    return 0;
}
