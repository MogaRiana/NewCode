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

const int NMAX = 1002;
const int MOD = 123457;

int mod(int n) { return (n < MOD) ? n : n % MOD; }
int mult(int x, int y) { return (x * y) % MOD; }

int bpow(int n, int p) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return mod(n);
  }

  if (p % 2 == 0) {
    int ans = bpow(n, p / 2);
    return mult(ans, ans);
  } else {
    return mult(bpow(n, p - 1), mod(n));
  }
}

int dp[NMAX][2];
int dp1[NMAX][NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  cout << 52 * bpow(50, n - 1) << " ";

  dp[1][0] = 26;
  dp[1][1] = 26;

  for (int i = 2; i <= n; i++) {
    dp[i][0] = ((dp[i - 1][0] * 26) % MOD + (dp[i - 1][1] * 26) % MOD) % MOD;

    dp[i][1] = (dp[i - 1][0] * 26) % MOD;
  }

  cout << (dp[n][0] + dp[n][1]) % MOD << " ";

  dp1[1][1] = 5;
  dp1[1][0] = 21;

  for (int i = 2; i <= n; i++) {
    dp1[i][0] = (dp1[i - 1][0] * 21) % MOD;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(i, k); j++) {
      dp1[i][j] =
          ((dp1[i - 1][j] * 21) % MOD + (dp1[i - 1][j - 1] * 5) % MOD) % MOD;
    }
  }

  int sum = 0;
  for (int j = 0; j <= k; j++) {
    sum = (sum + dp1[n][j]) % MOD;
  }

  cout << sum << endl;

  return 0;
}