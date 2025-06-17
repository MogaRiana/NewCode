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

const int MOD = 2011;
const int NMAX = 1000002;

int dp[NMAX][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"minusk.in"};
  ofstream cout{"minusk.out"};

  i64 n, k;
  cin >> n >> k;

  dp[1][1] = dp[1][0] = 1;
  dp[0][1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    dp[i][0] = dp[i][1];

    if (i >= k) {
      dp[i][0] = (dp[i][0] - dp[i - k][1]) % MOD;
    }

    if (dp[i][0] < 0) {
      dp[i][0] += MOD;
    }
  }

  cout << (dp[n][1] + dp[n][0]) % MOD << endl;

  return 0;
}