#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    i64 k, n, crt = 0;
    cin >> k >> n;
    vi64 v(n);
    vector<char> c(n);
    for(i64 i = 0; i < n; i++){
        cin >> v[i] >> c[i];
    }
    for(i64 i = 0; i < n; i++){
        crt += v[i];
        if(crt < 210){
            if(c[i] == 'T' && k + 1 <= 8){
                k++;
            }
            else if(k + 1 > 8){
                k = 1;
            }
        }
        else{
            cout << k << endl;
            break;
        }
    }
    return 0;
}
