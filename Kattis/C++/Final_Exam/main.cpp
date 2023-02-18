#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n, s = 0;
    cin >> n;
    char ans[n], ansh[n];
    ansh[n] = 'E';
    for(i64 i = 0; i < n; i++){
        cin >> ans[i];
    }
    for(i64 i = 0; i < n - 1; i++){
        ansh[i] = ans[i + 1];
    }
    for(i64 i = 0; i < n; i++){
        if(ansh[i] == ans[i]){
            s++;
        }
    }
    cout << s << endl;
    return 0;
}
