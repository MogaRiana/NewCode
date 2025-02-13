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
typedef vec<vi32> vv32;
typedef vec<p64> vp64;
typedef vec<str> vstr;

const int NMAX = 102;
int vis[NMAX];
int dist[NMAX];
int res;
int n, m, k;

void bfs(vv32 &g) {
  deque<int> q;

  q.push_back(k);
  vis[k] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop_front();

    for (auto &c : g[node]) {
      if (!vis[c]) {
        vis[c] = 1;
        dist[c] = dist[node] + 1;
        q.push_back(c);
      }
    }

    res = max(res, dist[node]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;

  vv32 g(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs(g);

  // cout << res << endl;
  for (int i = 1; i <= n; i++) {
    if (dist[i] == res) {
      cout << i << " ";
    }
  }

  return 0;
}