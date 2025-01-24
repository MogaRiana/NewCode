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

const int NMAX = 10002;
const int MOD = 123457;

int dp[NMAX][NMAX];

int div(int n, vi32 &d) {
  for (int i = 1; i * i < n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      d.push_back(n / i);
    }
  }

  srt(d);
  return sz(d);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vi32 d(0);
  int n;
  cin >> n;

  int x = div(n, d);
  dp[0][0] = 1;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < x; j++) {
      if (i - d[j] >= 0) {
        dp[i][j] = (dp[i][j - 1] + dp[i - d[j]][j]) % MOD;
      }
    }
  }

  cout << dp[n][x] << endl;

  return 0;
}