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

const int MOD = 777013;
const int NMAX = 100002;
i64 dp[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  dp[1] = dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }

  i64 sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = (sum + dp[i]) % MOD;
  }

  cout << sum << endl;

  return 0;
}