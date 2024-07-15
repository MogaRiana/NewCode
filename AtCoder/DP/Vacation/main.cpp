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

  i64 n;
  cin >> n;

  vv v(n, vi64(3));
  vv dp(n, vi64(3));

  for (i64 i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }

  dp[0][0] = v[0][0];
  dp[0][1] = v[0][1];
  dp[0][2] = v[0][2];

  for (i64 i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
  }

  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;

  return 0;
}