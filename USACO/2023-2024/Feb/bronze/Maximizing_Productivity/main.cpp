#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  vi64 c(n), t(n);
  for (i64 i = 0; i < n; i++) {
    cin >> c[i];
  }
  for(i64 i = 0; i < n; i++){
    cin >> t[i];
    t[i] = c[i] - t[i];
  }

  sort(t.begin(), t.end());
  while(q--){
    i64 v, s;
    cin >> v >> s;
    
    i64 a = -1, l = 0, r = t.size() - 1;

    while (l <= r) {
      i64 m = l + (r - l) / 2;

      if (t[m] > s) {
        a = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    if(n - a >= v and a != -1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
  }

  return 0;
} 