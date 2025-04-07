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

vec<vp64> dp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"summax1.in"};
  ofstream cout{"summax1.out"};

  int cer, n, l, r;
  cin >> cer;
  cin >> n >> l >> r;

  dp.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i].resize(i + 1);
    for (int j = 1; j <= i; j++) {
      cin >> dp[i][j].ft;
      if (i == n) {
        dp[i][j].sd = 1;
      }
    }
  }

  for (int i = n - 1; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
      int tmp = dp[i][j].ft;

      if (dp[i + 1][j].ft == dp[i + 1][j + 1].ft) {
        dp[i][j].ft = dp[i + 1][j].ft;
        if (1ll * dp[i + 1][j + 1].sd + 1ll * dp[i + 1][j].sd > 2e9) {
          dp[i][j].sd = 2e9 + 1;
        } else {
          dp[i][j].sd = dp[i + 1][j + 1].sd + dp[i + 1][j].sd;
        }
      } else {
        if (dp[i + 1][j].ft > dp[i + 1][j + 1].ft) {
          dp[i][j] = dp[i + 1][j];
        } else {
          dp[i][j] = dp[i + 1][j + 1];
        }
      }

      dp[i][j].ft += tmp;
    }
  }

  if (cer == 1) {
    cout << dp[1][1].sd << endl;
    return 0;
  }

  for (int i = l; i <= r; i++) {
    int val = 1, s = 0;
    cout << 1 << " ";

    for (int j = 1; j < n; j++) {
      if (dp[j + 1][val].ft == dp[j + 1][val + 1].ft and
          s + dp[j + 1][val].sd < i) {
        s += dp[j + 1][val].sd;
        val++;
      } else if (dp[j + 1][val + 1].ft > dp[j + 1][val].ft) {
        val++;
      }
      cout << val << " ";
    }

    cout << endl;
  }

  return 0;
}