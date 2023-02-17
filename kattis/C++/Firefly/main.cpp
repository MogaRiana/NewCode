#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n, h, x;
  cin >> n >> h;
  vi64 u;
  vi64 d;

  for (i64 i = 0; i < n; i++) {
    cin >> x;
    if (i % 2 == 0) {
      d.push_back(x);
    } else {
      u.push_back(x);
    }
  }
  sort(d.begin(), d.end());
  sort(u.begin(), u.end());

  i64 res1 = 1e9, res2 = 0;

  for (i64 i = 1; i <= h; i++) {
    i64 l = 0, r = d.size() - 1, resd = d.size(), resu = u.size();

    while (l <= r) {
      i64 m = l + (r - l) / 2;

      if (d[m] >= i) {
        resd = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    l = 0, r = u.size() - 1;

    while (l <= r) {
      i64 m = l + (r - l) / 2;

      if (u[m] >= h - i + 1) {
        resu = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    i64 sol = d.size() - resd + u.size() - resu;

    if (sol < res1) {
      res1 = sol;
      res2 = 1;
    } else if (res1 == sol) {
      res2++;
    }
  }

  cout << res1 << " " << res2 << endl;

  return 0;
}
