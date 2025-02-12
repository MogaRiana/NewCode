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
int par[NMAX];
int n, p, q, r;

void bfs(int st, int fn, vv &g) {
  for (int i = 0; i <= n; i++) {
    par[i] = 0;
  }

  deque<i64> q;
  q.push_back(st);

  par[st] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();

    if (u == fn)
      break;

    for (auto &v : g[u]) {
      if (par[v] == 0) {
        par[v] = u;
        q.push_back(v);
      }
    }
  }
}

vi32 path1(0), path2(0);
void slv(int st, int fn, vi32 &path) {
  if (st == fn) {
    return;
  }

  slv(par[st], fn, path);
  path.push_back(st);
}

void solve(int st, int fn, vv &g, vi32 &path) {
  bfs(st, fn, g);
  path.push_back(st);
  slv(fn, st, path);
}

void print() {
  ofstream cout{"lant1.out"};

  cout << sz(path1) + sz(path2) - 1 << endl;
  for (int i = 0; i < path1.size(); i++) {
    cout << path1[i] << " ";
  }
  for (int i = 1; i < path1.size(); i++) {
    cout << path2[i] << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"lant1.in"};
  ofstream cout{"lant1.out"};

  cin >> n >> p >> q >> r;
  vv g(n + 1);
  int u, v;

  while (cin >> u >> v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  solve(p, r, g, path1);
  solve(r, q, g, path2);
  print();

  return 0;
}