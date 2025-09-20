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

bool solve(vv &g, vec<bool> &vis, i64 st, vi64 &p, i64 pp) {
  vis[st] = true;
  p[st] = pp;

  for (auto &x : g[st]) {
    if (p[x] == 0) {
      if (solve(g, vis, x, p, 3 - pp) == false) {
        return false;
      }
    } else if (p[x] == pp) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 m, n;
  cin >> m >> n;

  vec<vi64> g(m);
  for (i64 i = 0; i < n; i++) {
    i64 a, b;
    cin >> a >> b;

    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  vec<bool> vis(m, false);
  vi64 p(m, 0);

  bool ok = true;
  for (i64 i = 0; i < m; i++) {
    if (!vis[i]) {
      bool temp = solve(g, vis, i, p, 1);
      if (!temp) {
        ok = false;
        break;
      }
    }
  }

  if (ok) {
    for (i64 i = 0; i < m; i++) {
      cout << p[i] << " ";
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}