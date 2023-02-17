#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n, d, h, m;
    char z;
    cin >> n;
    for(i64 i = 0; i < n; i++){
        cin >> z;
        if(z == 'F'){
            cin >> d >> h >> m;
            i64 t = (h * 60) + m + d;
            h = t / 60;
            if(h >= 24){
                h -= 24;
            }
            m = t % 60;
            cout << h << " " << m << endl;
        }
        else if(z == 'B'){
            cin >> d >> h >> m;
            i64 t = (h * 60) + m - d;
            if(t < 0){
                t += 24 * 60;
            }
            h = t / 60;
            if(h >= 24){
                h -= 24;
            }
            m = t % 60;
            cout << h << " " << m << endl;
        }
    }
    return 0;
}
