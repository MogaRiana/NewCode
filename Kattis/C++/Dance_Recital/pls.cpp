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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, res = 1e9;
  cin >> n;

  vi64 v(n);
  vector<str> s(n);
  map<string, map<char, i64>> m;
  for (i64 i = 0; i < n; i++) {
    cin >> s[i];
    for (auto &c : s[i]) {
      m[s[i]][c]++;
    }
    v[i] = i;
  }

  map<pair<i64, i64>, i64> dp;

  do {
    i64 crt = 0;
    for (i64 i = 0; i < n - 1; i++) {
      i64 cnt = 0;
      pair<i64, i64> p = {v[i], v[i + 1]};
      if (dp.count(p)) {
        crt += dp[p];
      } else {
        bool ok = false;
        for (auto &c : m[s[v[i]]]) {
          if (crt > res) {
            ok = true;
            break;
          }
          if (m[s[v[i + 1]]].count(c.first)) {
            cnt++;
          }
        }
        dp[p] = cnt;
        crt += cnt;
        if (ok) {
          break;
        }
      }
    }

    res = min(res, crt);
    if (res == 0) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << res << endl;

  return 0;
}