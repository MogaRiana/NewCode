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

int calc(vi64 dist) {
  int res = 0;
  for (int i = 1; i < sz(dist); i++) {
    res += dist[i];
  }

  return res;
}

int dijkstra(int p, int n, vec<vp64> &g) {
  priority_queue<p64, vp64, greater<p64>> pq;
  vi64 dist(n + 1, 1e9);
  vec<bool> vis(n + 1, false);

  pq.push({0, p});
  dist[p] = 0;

  while (!pq.empty()) {
    int node = pq.top().sd;
    pq.pop();

    if (vis[node]) {
      continue;
    }

    vis[node] = true;
    for (auto &c : g[node]) {
      if (dist[c.sd] > dist[node] + c.ft) {
        dist[c.sd] = dist[node] + c.ft;
        pq.push({dist[c.sd], c.sd});
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   if (dist[i] == 1e9) {
  //     cout << -1 << " ";
  //     continue;
  //   }
  //   cout << dist[i] << " ";
  // }
  // cout << endl;

  return calc(dist);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"firma.in"};
  ofstream cout{"firma.out"};

  int n, m;
  cin >> n >> m;

  vec<vp64> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({c, v});
    g[v].push_back({c, u});
  }

  int res = 1e9, firma = 0;

  for (int i = 1; i <= n; i++) {
    int d = dijkstra(i, n, g);
    // cout << d << endl;
    if (d < res) {
      res = d;
      firma = i;
    }
  }

  cout << firma << endl;

  return 0;
}