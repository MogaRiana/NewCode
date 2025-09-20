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

struct DSU {
  vi32 p, size;
  int cnt;

  DSU(int n) {
    p.resize(n + 1);
    size.resize(n + 1, 1);
    cnt = 0;

    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }

  int find(int x) {
    if (p[x] == x) {
      return x;
    }

    return p[x] = find(p[x]);
  }

  void Union(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a == b) {
      return;
    }

    if (size[a] > size[b]) {
      p[b] = a;
      size[a] += size[b];
    } else {
      p[a] = b;
      size[b] += size[a];
    }

    cnt--;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"closing.in"};
  ofstream cout{"closing.out"};

  int n, m;
  cin >> n >> m;

  DSU eep(n);
  vv g(n + 1);
  vec<bool> vis(n + 1, false);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  vi32 v(n);
  for (auto &x : v) {
    cin >> x;
  }

  rvs(v);
  vec<str> res;
  res.reserve(n + 1);

  for (auto &x : v) {
    vis[x] = true;
    eep.cnt++;

    for (auto &c : g[x]) {
      if (vis[c]) {
        eep.Union(x, c);
      }
    }

    if (eep.cnt == 1) {
      res.push_back("YES");
    } else {
      res.push_back("NO");
    }
  }

  for (int i = sz(res) - 1; i >= 0; i--) {
    cout << res[i] << endl;
  }

  return 0;
}