#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n, t;
    cin >> n;
    for(i64 i = 0; i < n; i++){
        i64 m = 1, s = 0;
        while(cin >> t){
            if(t == 0){
                break;
            }
            if(t > m * 2){
                s += t - (m * 2);
            }
            m = t;
        }
        cout << s << endl;
    }
    return 0;
}
