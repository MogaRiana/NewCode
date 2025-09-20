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
typedef pair<i32, i32> p32;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

vec<vec<p32>> g;
vec<bool> vis, f;
int n, m;
void dfs(int st, int e) {
  vis[st] = true;
  for (auto &x : g[st]) {
    if (!vis[x.ft] and x.sd >= e) {
      vis[x.ft] = true;
      dfs(x.ft, e);
    }
  }
}

bool ver() {
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (f[i] and !vis[i]) {
      ok = false;
    }
    vis[i] = false;
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"wormsort.in"};
  ofstream cout{"wormsort.out"};

  cin >> n >> m;

  bool ok = true;
  vi32 v(n + 1);
  f.resize(n + 1, false);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];

    if (v[i] != i) {
      ok = false;
      f[i] = true;
    }
  }

  vi32 e(m + 1);
  g.resize(n + 1);
  vis.resize(n + 1, false);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b >> e[i];

    g[a].push_back({b, e[i]});
    g[b].push_back({a, e[i]});
  }

  if (ok) {
    cout << -1 << endl;
    return 0;
  }

  srt(e);
  int l = 1, r = m;
  int res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    for (int i = 1; i <= n; i++) {
      if (v[i] != i) {
        dfs(i, e[mid]);
        break;
      }
    }
    if (ver()) {
      l = mid + 1;
      res = e[mid];
    } else {
      r = mid - 1;
    }
  }

  cout << res << endl;

  return 0;
}