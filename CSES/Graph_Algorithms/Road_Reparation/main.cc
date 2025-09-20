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

struct DSU {
  vi64 p, size;
  i64 comp = 0;
  i64 mx_c = 0;
  i64 res = 0;

  DSU(int n) {
    p.resize(n + 1, 0);
    size.resize(n + 1, 1);
    comp = n;

    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }

  i64 find(i64 x) {
    if (p[x] == x) {
      return x;
    }

    return p[x] = find(p[x]);
  }

  void Union(i64 a, i64 b, i64 d) {
    i64 x = find(a);
    i64 y = find(b);

    if (x == y) {
      return;
    }

    if (size[x] > size[y]) {
      p[y] = x;
      size[x] += size[y];
    } else {
      p[x] = p[y];
      size[y] += size[x];
    }

    res += d;
    comp--;
    mx_c = max({mx_c, size[a], size[b]});
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vec<pair<i64, p64>> g(m);
  for (int i = 0; i < m; i++) {
    cin >> g[i].sd.ft >> g[i].sd.sd >> g[i].ft;
  }

  DSU e(n);

  srt(g);
  for (int i = 0; i < m and e.comp != 1; i++) {
    i64 u = g[i].sd.ft, v = g[i].sd.sd;
    i64 d = g[i].ft;

    e.Union(u, v, d);
  }

  if (e.comp == 1) {
    cout << e.res << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}