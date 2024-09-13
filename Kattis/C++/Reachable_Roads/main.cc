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

void bfs(vv &g, vec<bool> &vis, i64 st) {
  deque<i64> q;
  q.push_back(st);

  while (!q.empty()) {
    i64 u = q.front();
    q.pop_front();

    if (vis[u]) {
      continue;
    }
    vis[u] = true;

    for (auto &v : g[u]) {
      if (!vis[v]) {
        q.push_back(v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, m;
    cin >> n >> m;

    vv g(n);
    for (i64 i = 0; i < m; i++) {
      i64 u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vec<bool> vis(n, false);
    i64 crt = 0;
    for (i64 i = 0; i < n; i++) {
      if (!vis[i]) {
        bfs(g, vis, i);
        crt++;
      }
    }

    cout << crt - 1 << endl;
  }

  return 0;
}