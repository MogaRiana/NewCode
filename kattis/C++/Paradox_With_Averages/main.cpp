#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main()
{
    i64 t;
    cin >> t;
    for(i64 i = 0; i < t; i++){
        i64 a, b, crt = 0;
        cin >> a >> b;
        v64 cs(a);
        v64 e(b);
        double mcs = 0, me = 0;
        for(i64 i = 0; i < a; i++){
            cin >> cs[i];
            mcs += cs[i];
        }
        mcs /= a;
        for(i64 i = 0; i < b; i++){
            cin >> e[i];
            me += e[i];
        }
        me /= b;
        for(i64 i = 0; i < a; i++){
            if(cs[i] < mcs && cs[i] > me){
                crt++;
            }
        }
        cout << crt << endl;
    }
    return 0;
}
