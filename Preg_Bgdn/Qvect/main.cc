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

i64 ub(i64 x, vi64 &v) {
  i64 l = 0, r = sz(v) - 1;
  i64 m;
  while (l <= r) {
    m = (l + r) / 2;
    if (v[m] <= x) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  vv v(n);
  for (i64 i = 0; i < n; i++) {
    i64 k;
    cin >> k;
    for (i64 j = 0; j < k; j++) {
      i64 x;
      cin >> x;
      v[i].push_back(x);
    }
  }

  while (q--) {
    i64 t, i, j;
    cin >> t >> i >> j;

    if (t == 1) {

    } else {
      i64 l = -1e9, r = 1e9;
      i64 res = 1e9;
      while (l <= r) {
        i64 cnt = 0, k = 0;
        i64 m = (l + r) / 2;
        for (i64 ii = i - 1; ii < j; ii++) {
          i64 idx = ub(m, v[ii]);
          cnt += idx;
          k += sz(v[ii]);
        }

        if (cnt >= (k + 1) / 2) {
          r = m - 1;
        } else {
          res = m;
          l = m + 1;
        }
      }

      cout << res << endl;
    }
  }

  return 0;
}