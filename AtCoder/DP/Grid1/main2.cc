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

const i32 MOD = 1e9 + 7;
i32 dp[1002][1002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 l, c;
  cin >> l >> c;

  i32 v[l + 1][c + 1];
  for (i64 i = 1; i <= l; i++) {
    for (i64 j = 1; j <= c; j++) {
      char cc;
      cin >> cc;

      v[i][j] = (cc == '.') ? 0 : 1;
    }
  }

  dp[1][1] = 1;
  for (i32 i = 1; i <= l; i++) {
    if (v[i][0] == 0) {
      dp[i][0] = 1;
    } else {
      break;
    }
    for (i32 j = 1; j <= c; j++) {
      if (v[i][j] == 0) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      } else {
        dp[i][j] = 0;
      }
    }
  }

  cout << dp[l][c] << endl;

  return 0;
}