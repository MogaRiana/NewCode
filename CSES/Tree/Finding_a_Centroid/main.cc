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

const int NMAX = 200002;
int n;
vi32 g[NMAX];
int sz[NMAX];

int dfs(int crt, int p) {
  int res = 1;
  for (auto &c : g[crt]) {
    if (c != p) {
      res += dfs(c, crt);
    }
  }

  sz[crt] = res;
  return res;
}

int centroid(int node, int p) {
  for (auto &c : g[node]) {
    if (c != p && sz[c] * 2 > n) {
      return centroid(c, node);
    }
  }

  return node;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0, -1);
  cout << centroid(0, -1) + 1 << endl;

  return 0;
}