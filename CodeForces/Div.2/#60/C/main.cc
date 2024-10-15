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

p64 from, to;
i64 n;
str mv;
vp64 d;

bool check(i64 ans) {
  i64 an = ans / n;
  p64 ff = {from.ft + d[n].ft * an, from.sd + d[n].sd * an};
  ff.ft += d[ans % n].ft;
  ff.sd += d[ans % n].sd;

  i64 dx = abs(ff.ft - to.ft);
  i64 dy = abs(ff.sd - to.sd);
  return (dx + dy) <= ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> from.ft >> from.sd;
  cin >> to.ft >> to.sd;
  cin >> n >> mv;
  d.assign(n + 1, {0, 0});

  p64 pp = from;
  for (i64 i = 1; i <= n; i++) {
    char c = mv[i - 1];
    if (c == 'U') {
      pp.sd += 1;
    } else if (c == 'D') {
      pp.sd -= 1;
    } else if (c == 'L') {
      pp.ft -= 1;
    } else if (c == 'R') {
      pp.ft += 1;
    }

    d[i] = {pp.ft - from.ft, pp.sd - from.sd};
  }

  i64 l = 0, r = 1e18;
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}