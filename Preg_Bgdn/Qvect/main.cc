#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i32) x.size()
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
  int p = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (v[m] <= x) {
      l = m + 1;
      p = m;
    } else {
      r = m - 1;
    }
  }

  return p + 1;
}

int cnt(int i, int j, vv &v, int x) {
  int cnt = 0;
  for (int ii = i; ii <= j; ii++) {
    int idx = ub(x, v[ii]);
    cnt += idx;
  }

  return cnt;
}

int query_1(vi64 &a, vi64 &b) {
  int ret = INT_MAX;

  int j = 0;
  for (int i = 0; i < sz(a); i++) {
    while (j < sz(b) && b[j] <= a[i]) {
      j++;
    }
    if (j > 0) {
      ret = min((i64)ret, a[i] - b[j - 1]);
    }
    if (j < sz(b)) {
      ret = min((i64)ret, b[j] - a[i]);
    }
  }

  return ret;
}

int main() {
#ifndef LOCAL
  freopen("qvect.in", "r", stdin);
  freopen("qvect.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  vv v(n);
  vector<int> sum(n);
  for (i64 i = 0; i < n; i++) {
    i64 k;
    cin >> k;
    sum[i] = k + (i > 0 ? sum[i - 1] : 0);

    v[i].resize(k);
    for (auto &x : v[i]) {
      cin >> x;
    }
  }

  while (q--) {
    i64 t, i, j;
    cin >> t >> i >> j;
    i--, j--;
    int k = sum[j] - (i > 0 ? sum[i - 1] : 0);
    if (t == 1) {
      cout << query_1(v[i], v[j]) << endl;
    } else {
      i64 l = -1e9, r = 1e9;
      i64 res = 1e9;
      while (l <= r) {
        i64 m = (l + r) / 2;
        if (cnt(i, j, v, m) >= k / 2) {
          r = m - 1;
          res = m;
        } else {
          l = m + 1;
        }
      }
      cout << res << endl;
    }
  }

  return 0;
}