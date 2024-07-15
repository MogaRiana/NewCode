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

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 MOD = 1e9 + 7;
  i64 l, c;
  cin >> l >> c;

  vv v(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      char c;
      cin >> c;

      v[i][j] = (c == '.') ? 0 : 1;
    }
  }

  vv dp(l, vi64(c, 0));
  for (i64 i = 0; i < l; i++) {
    if (v[i][0] == 0) {
      dp[i][0] = 1;
    } else {
      break;
    }
  }
  for (i64 j = 0; j < c; j++) {
    if (v[0][j] == 0) {
      dp[0][j] = 1;
    } else {
      break;
    }
  }

  for (i64 i = 1; i < l; i++) {
    for (i64 j = 1; j < c; j++) {
      if (v[i][j] == 0) {
        if (v[i - 1][j] == 0 and v[i][j - 1] == 0) {
          dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        } else if (v[i - 1][j] == 0 and v[i][j - 1] == 1) {
          dp[i][j] = dp[i - 1][j] % MOD;
        } else if (v[i - 1][j] == 1 and v[i][j - 1] == 0) {
          dp[i][j] = dp[i][j - 1] % MOD;
        }
      }
    }
  }

  cout << dp[l - 1][c - 1] << endl;

  return 0;
}