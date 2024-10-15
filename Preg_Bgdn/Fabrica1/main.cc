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

i64 n;

i64 f(int t, vi32 &v) {
  i64 res = 0;
  for (i64 i = 0; i < n; i++) {
    res += t / v[i];
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 m;
  cin >> n >> m;

  vi32 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  i64 l = 1, r = 1e9;
  i64 res = 0;
  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    if (f(mid, v) >= m) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << res << endl;

  return 0;
}