#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n, s = 0;
    cin >> n;
    i64 a = n;
    while(a){
        s += a % 10;
        a /= 10;
    }
    if(n % s == 0){
        cout << n;
    }
    else{
        bool k = true;
        for(i64 i = n + 1; k; i++){
            i64 b = i;
            s = 0;
            while(b){
              s += b % 10;
              b /= 10;
            }
            if(i % s == 0){
                cout << i;
                k = false;
            }
        }
    }
    return 0;
}
