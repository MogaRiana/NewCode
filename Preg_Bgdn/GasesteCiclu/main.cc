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
int par[NMAX];
int n, m;

void ciclu(int st, int fn, vv &g) {
  cout << st << " ";
  if (st == fn) {
    return;
  }
  ciclu(par[st], fn, g);
}

bool ok = false;
void dfs(int node, vv &g) {
  for (auto &c : g[node]) {
    if (par[c] != 0 and par[node] != c and !ok) {
      cout << c << " ";
      ciclu(node, c, g);
      ok = true;
      return;
    }

    if (!par[c]) {
      par[c] = node;
      dfs(c, g);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  vv g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    par[i] = -1;
    dfs(i, g);
    if (ok) {
      break;
    }
  }

  return 0;
}