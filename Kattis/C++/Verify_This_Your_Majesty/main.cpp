#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    i64 n;
    cin >> n;
    vi64 x(n);
    vi64 y(n);
    bool ok = true;
    for(i64 i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(i64 i = 0; i < n; i++){
        for(i64 j = 0; j < n; j++){
            if(j != i){
                i64 a = abs(x[i] - x[j]);
                i64 b = abs(y[i] - y[j]);
                if((a >= 2 || b >= 2) && (x[i] != x[j] && y[i] != y[j])){
                    ok = true;
                }
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(!ok){
            break;
        }
    }
    if(ok){
        cout << "CORRECT" << endl;
    }
    else{
        cout << "INCORRECT" << endl;
    }
    return 0;
}
