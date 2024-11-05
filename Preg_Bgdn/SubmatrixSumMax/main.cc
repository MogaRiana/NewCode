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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  i64 res = -1e9;
  for (int u = 0; u < n; u++) {
    vi64 v(n, 0);
    for (int d = u; d < n; d++) {
      for (int i = 0; i < n; i++) {
        v[i] += a[d][i];
      }

      i64 sum = v[0];
      i64 c = v[0];
      for (int i = 1; i < n; i++) {
        c = max(v[i], c + v[i]);
        sum = max(sum, c);
      }

      res = max(res, sum);
    }
  }

  cout << res << endl;

  return 0;
}