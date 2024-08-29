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

i64 n, k;
i64 a[100004];
vi64 dp(1000004, 1e9);

void slv() {
  dp[0] = 0;

  for (i64 i = 1; i <= k; i++) {
    for (i64 j = 0; j < n; j++) {
      if (i - a[j] >= 0) {
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (i64 i = 0; i < n; i++) {
    cin >> a[i];
  }

  slv();

  if (dp[k] == 1e9) {
    cout << -1 << endl;
  } else {
    cout << dp[k] << endl;
  }

  return 0;
}