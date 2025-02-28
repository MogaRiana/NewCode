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

ofstream fout{"festivaluri.out"};
const int NMAX = 100;
int n, m, p, z, r;

int fest[NMAX];

void slv(vp64 &dist) {
  int cnt = 0;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (res + dist[i].ft <= p and fest[dist[i].sd]) {
      res += dist[i].ft;
      cnt++;
    }
  }

  fout << cnt << endl;
}

void dijkstra(int p, int n, vec<vp64> &g) {
  ofstream cout{"festivaluri.out"};

  vec<bool> vis(n + 1, false);
  vp64 dist(n + 1, {1e9, -1});

  dist[p].ft = 0;
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
      if (dist[edge.sd].ft > dist[node].ft + edge.ft) {
        dist[edge.sd].ft = dist[node].ft + edge.ft;
        dist[edge.sd].sd = edge.sd;
        pq.push({dist[edge.sd].ft, edge.sd});
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   fout << dist[i].ft << " ";
  // }
  // fout << endl;

  srt(dist);
  slv(dist);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"festivaluri.in"};

  cin >> n >> m >> p >> z >> r;

  vec<vp64> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({c, v});
    // g[v].push_back({c, u});
  }

  for (int i = 0; i < r; i++) {
    int x;
    cin >> x;
    fest[x] = 1;
  }

  dijkstra(z, n, g);

  return 0;
}