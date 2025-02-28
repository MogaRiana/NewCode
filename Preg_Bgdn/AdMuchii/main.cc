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

const int NMAX = 50002;
int n, m, k;
int spec[NMAX], vis[NMAX];
int nodes_con = 0;
vec<pair<int, pair<int, int>>> conex;
// {special node, {number of nodes, number of edges}}

int dfs(int st, vv &g, int cnt) {
  vis[st] = 1;
  nodes_con++;
  int sum = sz(g[st]);
  if (spec[st] == 1) {
    conex[cnt].ft = st;
  }

  for (auto &c : g[st]) {
    if (!vis[c]) {
      sum += dfs(c, g, cnt);
    }
  }

  return sum;
}

void slv(vv &g) {
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      nodes_con = 0;
      conex.push_back({false, {0, 0}});
      int xx = dfs(i, g, k);
      conex[k].sd = {nodes_con, xx / 2};
      k++;
    }
  }
}

i64 calc(int node) {
  i64 sum_nodes = 0;
  i64 sum_edges = 0;

  i64 sum_comp = 0;

  for (auto &x : conex) {
    if (x.ft == node or x.ft == 0) {
      sum_nodes += x.sd.ft;
      sum_edges += x.sd.sd;
    } else if (x.ft != node and x.ft != 0) {
      sum_comp += (x.sd.ft * (x.sd.ft - 1)) / 2;
      sum_comp -= x.sd.sd;
    }
  }

  i64 comb = (sum_nodes * (sum_nodes - 1)) / 2;
  return comb - sum_edges + sum_comp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"admuchii.in"};
  ofstream cout{"admuchii.out"};

  cin >> n >> m >> k;
  vv g(n + 1);

  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    spec[x] = 1;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  slv(g);

  // for (int i = 0; i < sz(conex); i++) {
  //   cout << conex[i].ft << " " << conex[i].sd.ft << " " << conex[i].sd.sd
  //        << endl;
  // }

  i64 res = -1;
  for (int i = 1; i <= n; i++) {
    if (spec[i]) {
      i64 x = calc(i);
      // cout << i << " " << x << endl;

      res = max(res, x);
    }
  }

  cout << res << endl;

  return 0;
}