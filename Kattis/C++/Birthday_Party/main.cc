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

map<p64, bool> v;
void bfs(vv &g, vec<bool> &vis, i64 st) {
  deq<i64> q;
  q.push_back(st);
  vis[st] = true;

  while (!q.empty()) {
    i64 u = q.front();
    q.pop_front();

    vis[u] = true;

    for (auto &c : g[u]) {
      if (!vis[c] and v[{u, c}]) {
        vis[c] = true;
        q.push_back(c);
      }
    }
  }
}

bool ver(vv &g) {
  vec<bool> vis(sz(g), false);

  for (int i = 0; i < sz(g); i++) {
    if (i > 0 and !vis[i]) {
      return true;
    }

    bfs(g, vis, i);
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  while (cin >> n >> m) {
    if (n == 0 and m == 0) {
      break;
    }

    vv g(n);
    for (int i = 0; i < m; i++) {
      i64 a, b;
      cin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);

      v[{a, b}] = true;
      v[{b, a}] = true;
    }

    bool ok = false;
    for (auto &x : v) {
      x.sd = false;
      if (ver(g)) {
        cout << "Yes" << endl;
        ok = true;
        break;
      }
      x.sd = true;
    }

    if (!ok) {
      cout << "No" << endl;
    }
  }

  return 0;
}