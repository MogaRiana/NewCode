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

void bfs(vv &g, vec<bool> &visit, i64 st, vi64 &p) {
  deque<i64> q;
  q.push_back(st);

  while (!q.empty()) {
    i64 u = q.front();
    q.pop_front();

    visit[u] = true;

    for (auto &v : g[u]) {
      if (!visit[v]) {
        visit[v] = true;
        p[v] = u;
        q.push_back(v);
      }
    }
  }
}

vi64 path(0);
bool slv(vv &g, vi64 &p, vec<bool> &vis, i64 e) {
  if (!vis[e]) {
    return false;
  }

  for (i64 i = e; i != -1; i = p[i]) {
    path.push_back(i);
  }
  rvs(path);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;

  vv g(n + 1);
  for (i64 i = 0; i < m; i++) {
    i64 u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vec<bool> visit(n + 1, false);
  vi64 parent(n + 1, -1);

  bfs(g, visit, 1, parent);

  if (slv(g, parent, visit, n)) {
    cout << sz(path) << endl;
    for (auto &i : path) {
      cout << i << " ";
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}