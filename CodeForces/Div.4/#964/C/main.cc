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

str solve() {
  str yy = "yes", nn = "no";

  i64 n, s, m;
  cin >> n >> s >> m;

  vp64 v(n);
  for (auto &p : v) {
    cin >> p.ft >> p.sd;
  }

  if (v[0].ft >= s or m - v[n - 1].sd >= s) {
    return yy;
  }

  for (i64 i = 1; i < n; i++) {
    i64 a = v[i].ft - v[i - 1].sd;
    if (a >= s) {
      return yy;
    }
  }

  return nn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}