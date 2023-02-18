#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main()
{
    i64 w, p;
    cin >> w >> p;
    v l(p);
    for(i64 i = 0; i < p; i++) {
        cin >> l[i];
    }
    l.push_back(w);
    v x;
    i64 m;
    for(i64 i = 0; i < l.size(); i++) {
        m = l[i];
        x.push_back(m);
        for(i64 j = 0; j < i; j++) {
            m = l[i] - l[j];
            x.push_back(m);
        }
    }
    sort(x.begin(), x.end());
    set<i64> a;
    for(i64 i = 0; i < x.size(); i++){
        a.insert(x[i]);
    }
    for(auto &i : a){
        cout << i << " ";
    }
    return 0;
}
