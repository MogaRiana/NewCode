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

const int MOD = 4001;
const int NMAX = 1002;

int dp[NMAX][3];
int f[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"divtrei.in"};
  ofstream cout{"divtrei.out"};

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    f[x % 3]++;
  }

  dp[1][0] = f[0];
  dp[1][1] = f[1];
  dp[1][2] = f[2];

  for (int i = 2; i <= k; i++) {
    dp[i][0] =
        (dp[i - 1][0] * f[0] + dp[i - 1][1] * f[2] + dp[i - 1][2] * f[1]) % MOD;
    dp[i][1] =
        (dp[i - 1][0] * f[1] + dp[i - 1][1] * f[0] + dp[i - 1][2] * f[2]) % MOD;
    dp[i][2] =
        (dp[i - 1][0] * f[2] + dp[i - 1][1] * f[1] + dp[i - 1][2] * f[0]) % MOD;
  }

  cout << dp[k][0] << endl;

  return 0;
}