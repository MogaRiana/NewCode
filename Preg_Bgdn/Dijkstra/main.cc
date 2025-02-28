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

void dijkstra(int p, int n, vec<vp64> &g) {
  ofstream cout{"dijkstra.out"};

  vi64 dist(n + 1, 1e9);
  vec<bool> vis(n + 1, false);

  dist[p] = 0;
  priority_queue<p64, vector<p64>, greater<p64>> pq;

  pq.push({0, p});

  while (!pq.empty()) {
    int node = pq.top().sd;
    pq.pop();

    if (vis[node]) {
      continue;
    }

    vis[node] = true;
    for (auto &edge : g[node]) {
      if (dist[edge.sd] > dist[node] + edge.ft) {
        dist[edge.sd] = dist[node] + edge.ft;
        pq.push({dist[edge.sd], edge.sd});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i] == 1e9) {
      cout << -1 << " ";
      continue;
    }
    cout << dist[i] << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"dijkstra.in"};

  int n, p;
  cin >> n >> p;

  vec<vp64> g(n + 1);
  int u, v, c;
  while (cin >> u >> v >> c) {
    g[u].push_back({c, v});
  }

  dijkstra(p, n, g);

  return 0;
}