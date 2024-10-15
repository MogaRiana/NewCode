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

  i64 n;
  cin >> n;

  vi64 a(n);
  for (i64 i = 0; i < n; i++) {
    cin >> a[i];
  }

  vi64 ll(n), rr(n);
  ll[0] = a[0];
  for (i64 i = 1; i < n; i++) {
    ll[i] = max(ll[i - 1], a[i]);
  }

  rr[n - 1] = a[n - 1];
  for (i64 i = n - 2; i >= 0; i--) {
    rr[i] = min(rr[i + 1], a[i]);
  }

  i64 res = -1e9;
  for (i64 p = 0; p < n - 1; p++) {
    res = max(res, ll[p] - rr[p + 1]);
  }

  cout << res << endl;

  return 0;
}