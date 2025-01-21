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

const int NMAX = 102;
i64 dp[NMAX][NMAX];
i64 a[NMAX][NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"sumtri.in"};
  ofstream cout{"sumtri.out"};

  int n;
  cin >> n;

  int k = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      cin >> a[i][j];
    }
    k++;
  }

  dp[1][1] = a[1][1];
  i64 res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
      res = max(res, dp[i][j]);
    }
  }

  cout << res << endl;

  return 0;
}