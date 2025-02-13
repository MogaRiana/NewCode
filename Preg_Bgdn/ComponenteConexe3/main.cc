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
typedef vec<vi32> vv32;
typedef vec<p64> vp64;
typedef vec<str> vstr;

const int NMAX = 102;
int vis[NMAX];
int res_size = 0;
int res_node = -1;
int n;

void bfs(int st, vv32 &g, int nr) {
  int resn = st;
  int size = 1;
  deque<int> q;

  q.push_back(st);
  vis[st] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop_front();

    for (auto &c : g[node]) {
      if (!vis[c]) {
        vis[c] = 1;
        q.push_back(c);
        size++;
        resn = min(resn, c);
      }
    }
  }

  if (size > res_size) {
    res_size = size;
    res_node = resn;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"componenteconexe3.in"};
  ofstream cout{"componenteconexe3.out"};

  cin >> n;
  vv32 g(n + 1);
  int u, v;
  while (cin >> u >> v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      bfs(i, g, cnt);
      cnt++;
    }
  }

  cout << res_node << " " << res_size << endl;

  return 0;
}