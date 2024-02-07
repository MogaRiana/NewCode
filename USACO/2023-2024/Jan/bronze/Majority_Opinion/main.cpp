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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    map<i64, i64> m;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;
      m[x]++;
    }

    i64 mm = -1e9;
    for (auto &x : m) {
      mm = max(mm, x.second);
    }
    vi64 res;
    for (auto &x : m) {
      if (x.second == mm) {
        res.push_back(x.first);
      }
    }

    if ((mm <= n / 2 and res.size() == 1) or (n == 2 and mm == 1)) {
      cout << -1;
    } else {
      cout << res[0];
      for (i64 i = 1; i < res.size(); i++) {
        cout << " " << res[i];
      }
    }

    cout << endl;
  }

  return 0;
}
