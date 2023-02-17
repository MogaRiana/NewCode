#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    cin >> n;
    for(i64 i = 0; i < n; i++){
        i64 r, e, c;
        cin >> r >> e >> c;
        i64 d = e - c;
        if(d < r){
            cout << "do not advertise" << endl;
            continue;
        }
        if(d == r){
            cout << "does not matter" << endl;
            continue;
        }
        if(d > r){
            cout << "advertise" << endl;
            continue;
        }
    }
    return 0;
}
