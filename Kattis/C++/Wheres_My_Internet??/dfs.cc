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

void dfs(vv &g, vec<bool> &visit, i64 st) {
  visit[st] = true;
  for (auto &u : g[st]) {
    if (!visit[u]) {
      dfs(g, visit, u);
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;

  vv g(n + 1);
  for (i64 i = 0; i < m; i++) {
    i64 u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vec<bool> visit(n + 1, false);
  dfs(g, visit, 1);

  i64 crt = 0;
  for (i64 i = 1; i <= n; i++) {
    if (!visit[i]) {
      crt++;
    }
  }

  if (crt == 0) {
    cout << "Connected" << endl;
  } else {
    for (i64 i = 1; i <= n; i++) {
      if (!visit[i]) {
        cout << i << endl;
      }
    }
  }

  return 0;
}