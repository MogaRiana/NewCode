#include <bits/stdc++.h>
#include <queue>

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

const int NMAX = 801;
int dr[NMAX], vis[NMAX];
int dp[NMAX][NMAX];

void dfs1(int st, int d, int &res, vec<vp64> &g) {
  vis[st] = 1;
  for (auto &c : g[st]) {
    if (!vis[c.sd] and c.ft <= d) {
      vis[c.sd] = 1;
      res = max(res, dr[c.sd]);
      dfs1(c.sd, d, res, g);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"dragoni.in"};
  ofstream cout{"dragoni.out"};

  int p;
  int n, m;

  cin >> p >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> dr[i];
  }

  vec<vp64> g(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({w, y});
    g[y].push_back({w, x});
  }

  if (p == 1) {
    int res = 0;
    dfs1(1, dr[1], res, g);
    cout << res << endl;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = 1e9;
    }
  }

  priority_queue<pair<i64, p64>, vec<pair<i64, p64>>, greater<pair<i64, p64>>>
      pq; // dist drgn node

  pq.push({0, {1, 1}});
  vec<vec<bool>> vis(n + 1, vec<bool>(n + 1, false));
  dp[1][1] = 0; // node dragon

  while (!pq.empty()) {
    int node = pq.top().sd.sd;
    int type = pq.top().sd.ft;
    int distance = pq.top().ft;
    pq.pop();

    if (vis[node][type]) {
      continue;
    }

    vis[node][type] = true;

    for (auto crt : g[node]) {
      int vecin = crt.sd;
      int distance = crt.ft;

      if (dp[vecin][type] > dp[node][type] + distance and
          dr[type] >= distance) {
        dp[vecin][type] = dp[node][type] + distance;
        pq.push({dp[vecin][type], {type, vecin}});
      }

      if (dp[vecin][node] > dp[node][type] + distance and
          dr[node] >= distance) {
        dp[vecin][node] = dp[node][type] + distance;
        pq.push({dp[vecin][node], {node, vecin}});
      }
    }
  }

  int res = 1e9;
  for (int i = 1; i <= n; i++) {
    res = min(res, dp[n][i]);
  }

  cout << res << endl;

  return 0;
}