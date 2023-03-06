#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 min(i64 a, i64 b) {

  if (a < b) {
    return a;
  } else {
    return b;
  }
}

vv prefsum(vv &v, i64 n) {
  vv pref = v;

  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      pref[i][j] = min(pref[i][j], 1) + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }

  return pref;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n, p;
  cin >> n >> p;
  vv v(n + 1, vi64(n + 1, 0));

  for (i64 i = 0; i < p; i++) {
    i64 x, y;
    cin >> x >> y;

    v[x][y]++;
  }

  vv pref = prefsum(v, n);
  vector<pair<i64, i64>> div;
  for (i64 i = 1; i <= p; i++) {
    if (p % i == 0) {
      div.push_back({i, p / i});
    }
  }

  i64 m = 0, res = 0;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      for (i64 k = 0; k < div.size(); k++) {
        i64 x = i - div[k].first + 1;
        i64 y = j - div[k].second + 1;

        if (x > 0 && y > 0 && div[k].first != div[k].second) {
          res =
              pref[i][j] - pref[x - 1][j] - pref[i][y - 1] + pref[x - 1][y - 1];
        }
        m = max(res, m);
      }
    }
  }

  cout << p - m << endl;

  return 0;
}