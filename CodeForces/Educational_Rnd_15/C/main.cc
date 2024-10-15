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

  i64 n, m;
  cin >> n >> m;

  vi64 c(n), t(m);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  i64 l = 0, r = 2e9;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    bool ok = true;
    for (i64 e = 0; e < n; e++) {
      auto lb = lower_bound(t.begin(), t.end(), c[e] - mid);
      auto ub = upper_bound(t.begin(), t.end(), c[e] + mid);

      if (ub - lb == 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}