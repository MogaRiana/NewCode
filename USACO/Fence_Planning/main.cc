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

struct cow {
  int x, y;
};

struct coord {
  int x, y;
};

int bfs(vv &g, vec<cow> &c, vec<bool> &vis, int st) {
  deq<i64> q;
  q.push_back(st);
  vis[st] = true;

  coord mx;
  coord mn;

  mx.x = -1e9;
  mx.y = -1e9;
  mn.x = 1e9;
  mn.y = 1e9;

  while (!q.empty()) {
    i64 u = q.front();
    q.pop_front();
    vis[u] = true;

    for (auto &node : g[u]) {
      if (!vis[node]) {
        vis[node] = true;
        q.push_back(node);
      }

      mx.x = max(mx.x, c[node].x);
      mx.y = max(mx.y, c[node].y);
      mn.x = min(mn.x, c[node].x);
      mn.y = min(mn.y, c[node].y);
    }
  }

  int p = 2 * (mx.x - mn.x) + 2 * (mx.y - mn.y);
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"fenceplan.in"};
  ofstream cout{"fenceplan.out"};

  i64 n, m;
  cin >> n >> m;

  vec<cow> c(n);
  vv g(n);

  for (int i = 0; i < n; i++) {
    cin >> c[i].x >> c[i].y;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  i64 res = 1e9;
  vec<bool> vis(n, false);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      i64 p = bfs(g, c, vis, i);
      res = min(res, p);
    }
  }

  cout << res << endl;

  return 0;
}