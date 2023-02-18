#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vector<i64>> vv;

int main()
{
    string s;
    i64 k;
    cin >> s;
    for(i64 i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            k = i;
            break;
        }
    }
    for(i64 i = k; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}
