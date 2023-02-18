#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 a, b, crt = 0;
    cin >> a >> b;
    while(a != b){
        if(a > b){
            if(a % 2 == 0){
                a /= 2;
            }
            else{
                a++;
            }
        }
        else{
            a++;
        }
        crt++;
    }
    cout << crt;
    return 0;
}
