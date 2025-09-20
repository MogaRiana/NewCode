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

vi64 con(vv &g, vec<bool> &vis, i64 st) {
  vi64 res;
  deq<i64> q;
  q.push_back(st);
  vis[st] = true;

  while (!q.empty()) {
    i64 p = q.front();
    q.pop_front();
    vis[p] = true;
    res.push_back(p);

    for (auto &x : g[p]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push_back(x);
      }
    }
  }

  return res;
}

i64 bs(vi64 &v, i64 x) {
  i64 l = 0, r = sz(v) - 1;
  i64 r1 = 1e9, r2 = 1e9;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    if (v[mid] >= x) {
      r = mid - 1;
      r1 = abs(v[mid] - x);
    } else {
      l = mid + 1;
    }
  }

  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    if (v[mid] <= x) {
      l = mid + 1;
      r2 = abs(v[mid] - x);
    } else {
      r = mid - 1;
    }
  }

  return min(r1, r2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vv g(n + 1);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);
    }

    vi64 g1, gn;
    vec<bool> vis(n + 1, false);
    g1 = con(g, vis, 1);
    gn = con(g, vis, n);

    if (gn.empty()) {
      cout << 0 << endl;
      continue;
    }

    srt(g1);
    srt(gn);

    i64 res = 1e9;
    for (auto &x : g1) {
      i64 d = bs(gn, x);
      res = min(res, d);
    }

    for (int i = 2; i < n; i++) {
      if (!vis[i]) {
        vi64 v = con(g, vis, i);
        for (auto &x : v) {
          i64 d = bs(g1, x) + bs(gn, x);
          res = min(res, d);
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}