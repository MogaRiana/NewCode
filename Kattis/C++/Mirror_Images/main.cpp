#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main()
{
    i64 n;
    cin >> n;
    for(i64 i = 0; i < n; i++){
        i64 a, b;
        cin >> a >> b;
        vector<vector<char>> d(a, vector<char>(b));
        for(i64 i = 0; i < a; i++){
            for(i64 j = 0; j < b; j++){
                cin >> d[i][j];
            }
        }
        cout << "Test " << i + 1 << endl;
        for(i64 i = a - 1; i >= 0; i--){
            for(i64 j = b - 1; j >= 0; j--){
                cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
