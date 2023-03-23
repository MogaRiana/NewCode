#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, q;
    cin >> n >> q;
    vector<pair<i64, i64>> v(n);

    cin >> v[0].first;
    v[0].second = v[0].first;
    for (i64 i = 1; i < n; i++) {
      cin >> v[i].first;
      v[i].second = max(v[i - 1].second, v[i].first);
      v[i].first += v[i - 1].first;
    }

    for (i64 i = 0; i < q; i++) {
      i64 res = 0;
      i64 step;
      cin >> step;

      i64 l = 0, r = n - 1;
      while (l <= r) {
        i64 m = l + (r - l) / 2;

        if (step >= v[m].second) {
          res = v[m].first;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      cout << res << " ";
    }

    cout << endl;
  }

  return 0;
}