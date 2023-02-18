#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    i64 l, d, x;
    cin >> l >> d >> x;
    for(i64 i = l; i <= d; i++){
        i64 sum = 0, a = i;
        while(a){
            sum += a % 10;
            a /= 10;
        }
        if(sum == x){
            cout << i << endl;
            break;
        }
    }
    for(i64 i = d; i >= l; i--){
        i64 sum = 0, a = i;
        while(a){
            sum += a % 10;
            a /= 10;
        }
        if(sum == x){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
