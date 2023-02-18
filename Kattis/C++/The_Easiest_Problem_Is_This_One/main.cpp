#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        i64 b = n, sumn = 0;
        while(b) {
            sumn += b % 10;
            b /= 10;
        }
        i64 p = 11;
        while(true) {
            i64 sumx = 0, a = n * p;
            while(a) {
                sumx += a % 10;
                a /= 10;
            }
            if(sumx == sumn) {
                cout << p << endl;
                break;
            }
            p++;
        }
    }
    return 0;
}
