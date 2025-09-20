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

int bfs(vv &g, int st) {
  vec<bool> vis(sz(g), false);
  deq<i64> q;
  int res = 0;

  q.push_back(st);
  vis[st] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    vis[u] = true;
    res++;

    for (auto &c : g[u]) {
      if (!vis[c]) {
        q.push_back(c);
        vis[c] = true;
      }
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"moocast.in"};
  ofstream cout{"moocast.out"};

  int n;
  cin >> n;

  vp64 coord(n);
  vi64 p(n);
  for (int i = 0; i < n; i++) {
    cin >> coord[i].ft >> coord[i].sd >> p[i];
  }

  vv g(n);
  for (int i = 0; i < n; i++) {
    int xa = coord[i].ft, ya = coord[i].sd;
    int pa = p[i];
    for (int j = i + 1; j < n; j++) {
      int xb = coord[j].ft, yb = coord[j].sd;
      int pb = p[j];

      if (sqrt(pow((xa - xb), 2) + pow((ya - yb), 2)) <= pa) {
        g[i].push_back(j);
      }
      if (sqrt(pow((xa - xb), 2) + pow((ya - yb), 2)) <= pb) {
        g[j].push_back(i);
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, bfs(g, i));
  }

  cout << res << endl;

  return 0;
}