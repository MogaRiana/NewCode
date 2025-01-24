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
int dp[NMAX];
int h[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"rafturi.in"};
  ofstream cout{"rafturi.out"};

  int c, n;
  cin >> c >> n;

  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    h[a] = max(h[a], b);
  }

  dp[1] = h[1];
  dp[2] = max(h[1], h[2]);
  dp[3] = max(h[1], max(h[2], h[3]));

  for (int i = 4; i <= c; i++) {
    int c1 = h[i] + dp[i - 1];
    int c2 = max(h[i], h[i - 1]) + dp[i - 2];
    int c3 = max(h[i], max(h[i - 2], h[i - 1])) + dp[i - 3];

    dp[i] = min(c1, min(c2, c3));
  }

  int res = 0;
  for (int i = 1; i <= c; i++) {
    res = max(res, dp[i]);
  }

  cout << res << endl;

  return 0;
}