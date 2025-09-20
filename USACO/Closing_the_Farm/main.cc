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

void dfs(vv &g, vec<bool> &vis, vec<bool> &c, i64 st, i64 &res) {
  if (!vis[st] and !c[st]) {
    res++;
    vis[st] = true;

    for (auto &x : g[st]) {
      if (!vis[x]) {
        dfs(g, vis, c, x, res);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"closing.in"};
  ofstream cout{"closing.out"};

  i64 n, m;
  cin >> n >> m;

  vv g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }

  vec<bool> vis(n, false);
  vec<bool> c(n, false);
  i64 res = 0;
  dfs(g, vis, c, 1, res);

  if (res == n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  for (int i = 0; i < n - 1; i++) {
    res = 0;
    c[v[i]] = true;

    fill(vis.begin(), vis.end(), false);
    dfs(g, vis, c, v[n - 1], res);

    if (res == n - i - 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}