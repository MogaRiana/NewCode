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

const int N = (int)2e5 + 100;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vi32 f(N, 0);
    vi32 dp(N, 0);

    for (int i = 1; i <= n; i++) {
      i64 v;
      cin >> v;
      f[v]++;
    }

    for (int i = N; i > 0; i--) {
      int m = 0;
      for (int j = i; j < N; j += i) {
        m = max(dp[j], m);
      }
      dp[i] = f[i] + m;
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
      res = max(dp[i], res);
    }
    cout << n - res << endl;
  }

  return 0;
}