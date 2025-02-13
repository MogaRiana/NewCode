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
int vis[NMAX];
int res[NMAX];
int aux[NMAX];
int g[NMAX][NMAX];
int n, m;

void bfs(int st) {
  vi64 cc(0);
  deque<int> q;

  q.push_back(st);
  cc.push_back(st);
  vis[st] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop_front();

    for (int c = 1; c <= n; c++) {
      if (!vis[c] and g[node][c]) {
        vis[c] = 1;
        q.push_back(c);
      }
    }
  }
}

int conexe(int k) {
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i] and i != k) {
      bfs(i);
      cnt++;
    }
  }

  return cnt;
}

void modif0(int i) {
  for (int j = 1; j <= n; j++) {
    if (g[i][j] == 1) {
      g[i][j] = 0;
      g[j][i] = 0;
      aux[j] = 1;
    }
  }
}

void modif1(int i) {
  for (int j = 1; j <= n; j++) {
    if (g[i][j] == 0 and aux[j]) {
      g[i][j] = 1;
      g[j][i] = 1;
      aux[j] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"retea.in"};
  ofstream cout{"retea.out"};

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g[u][v] = 1;
    g[v][u] = 1;
  }

  int con = conexe(0);

  for (int i = 1; i <= n; i++) {
    modif0(i);

    int k = conexe(i);
    if (k != con) {
      res[i] = 1;
    }

    modif1(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }

  return 0;
}