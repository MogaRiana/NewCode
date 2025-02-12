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

const int NMAX = 102;
int n, m, k;
int dist[NMAX];

void bfs(i64 st, vv &g) {
  vec<bool> vis(n + 1, false);
  deque<i64> q;
  q.push_back(st);
  dist[st] = 0;

  while (!q.empty()) {
    i64 u = q.front();
    q.pop_front();

    vis[u] = true;

    for (auto &c : g[u]) {
      if (!vis[c]) {
        vis[c] = true;
        dist[c] = dist[u] + 1;
        q.push_back(c);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"dmin.in"};
  ofstream cout{"dmin.out"};

  cin >> n >> m;
  vv g(n + 1);
  for (i64 i = 0; i < m; i++) {
    i64 u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    bfs(a, g);
    cout << dist[b] << endl;
  }

  return 0;
}