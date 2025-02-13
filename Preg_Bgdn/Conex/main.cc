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
int n;
int vis[NMAX];

void bfs(int st, vv &g) {
  deque<int> q;
  q.push_back(st);

  while (!q.empty()) {
    int c = q.front();
    q.pop_front();

    for (auto &v : g[c]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.push_back(v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"conex.in"};
  ofstream cout{"conex.out"};

  cin >> n;
  vv g(n + 1);
  int u, v;

  while (cin >> u >> v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs(1, g);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << "NU" << endl;
      return 0;
    }
  }

  cout << "DA" << endl;

  return 0;
}