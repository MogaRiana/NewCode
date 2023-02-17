#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    double b, p, bpm, abpm, t;
    cin >> n;
    for(i64 i = 0; i < n; i++){
        cin >> b >> p;
        bpm = 60 * (b / p);
        t = p;
        abpm = 60 / t;
        cout.precision(4);
        cout << fixed << bpm - abpm << " " << bpm << " " << bpm + abpm << endl;
    }
    return 0;
}
