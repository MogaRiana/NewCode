#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

// typedef int64_t i64;
typedef int32_t i64;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
// typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, w, mv = 0;
  cin >> n >> w;

  vi64 g(n), v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> g[i] >> v[i];
    mv += v[i];
  }

  vv dp(n, vi64(mv + 1, 1e9));
  dp[0][0] = 0;
  dp[0][v[0]] = g[0];

  i64 res = 0;

  if (g[0] <= w) {
    res = v[0];
  }

  for (i64 i = 1; i < n; i++) {
    dp[i][0] = 0;
    for (i64 j = 0; j <= mv; j++) {
      if (j >= v[i]) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + g[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }

      if (dp[i][j] <= w) {
        res = max(res, j);
      }
    }
  }

  cout << res << endl;

  return 0;
}