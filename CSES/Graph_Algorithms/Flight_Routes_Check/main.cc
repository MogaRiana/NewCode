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

vec<bool> vis;
i64 n, m;

void dfs(vv &g, int st) {
  vis[st] = true;
  for (auto &x : g[st]) {
    if (!vis[x]) {
      dfs(g, x);
    }
  }
}

bool ver(int x) {
  for (i64 i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "NO" << endl;

      if (x == 1) {
        cout << 1 << " " << i + 1 << endl;
      } else {
        cout << i + 1 << " " << 1 << endl;
      }

      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  vv g1(n), g2(n);

  for (int i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;

    a--;
    b--;

    g1[a].push_back(b);
    g2[b].push_back(a);
  }

  vis.resize(n, false);
  dfs(g1, 0);

  if (!ver(1)) {
    return 0;
  }

  fill(vis.begin(), vis.end(), false);
  dfs(g2, 0);

  if (!ver(2)) {
    return 0;
  }

  cout << "YES" << endl;

  return 0;
}