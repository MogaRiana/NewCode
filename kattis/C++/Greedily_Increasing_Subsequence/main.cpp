#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main()
{
    i64 n;
    cin >> n;
    vi64 v(n);
    for(i64 i = 0; i < n; i++){
        cin >> v[i];
    }
    vi64 c;
    c.push_back(v[0]);
    i64 m = v[0];
    for(i64 i = 1; i < n; i++){
        if(m < v[i]){
            c.push_back(v[i]);
            m = v[i];
        }
    }
    cout << c.size() << endl;
    for(i64 i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    return 0;
}
