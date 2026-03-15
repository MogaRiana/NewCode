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

i64 dp[1001][1001];
i64 MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"turcane.in"};
  ofstream cout{"turcane.out"};

  int c;
  cin >> c;

  i64 m, n, p, q, r;
  cin >> m >> n >> p >> q >> r;

  if (c == 1) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = 1e15;
      }
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[1][1] = 0;

        dp[min(i + p, m)][j] = min(dp[min(i + p, m)][j], dp[i][j] + 1);

        dp[i][min(j + q, n)] = min(dp[i][min(j + q, n)], dp[i][j] + 1);

        dp[i + min(m - i, min(n - j, r))][j + min(m - i, min(n - j, r))] = min(
            dp[i + min(m - i, min(n - j, r))][j + min(m - i, min(n - j, r))],
            dp[i][j] + 1);

        dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + 1);
        dp[i + 1][j + 2] = min(dp[i + 1][j + 2], dp[i][j] + 1);
      }
    }

    cout << (dp[m][n]) % MOD << endl;
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dp[0][0] = 1;
        int s = 0;

        // dreapta
        for (int k = 1; j - k >= 0 and k <= p; k++) {
          s += dp[i][j - k];
        }

        // jos
        for (int k = 1; i - k >= 0 and k <= q; k++) {
          s += dp[i - k][j];
        }

        // diagonala
        for (int k = 1; i - k >= 0 and j - k >= 0 and k <= r; k++) {
          s += dp[i - k][j - k];
        }

        // cal
        int k = i - 1, l = j - 2;
        if (k >= 0 and l >= 0) {
          s += dp[k][l];
        }

        k = i - 2;
        l = j - 1;
        if (k >= 0 and l >= 0) {
          dp[i][j] = min(dp[i][j], dp[k][l]) % MOD;
          s += dp[k][l];
        }

        dp[i][j] = (s) % MOD;
      }
    }

    cout << (dp[m - 1][n - 1]) % MOD << endl;
  }

  return 0;
}