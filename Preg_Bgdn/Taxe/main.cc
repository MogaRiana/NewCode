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

const int NMAX = 102;
int a[NMAX][NMAX];
int d[NMAX][NMAX];
int v[NMAX][NMAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j, int n) {
  deque<p32> q;
  q.push_back({i, j});
  // v[i][j] = 1;
  d[i][j] = a[i][j];

  while (!q.empty()) {
    p32 p = q.front();
    q.pop_front();

    for (int k = 0; k < 4; k++) {
      int x = p.ft + dx[k];
      int y = p.sd + dy[k];

      if (x >= 1 && x <= n && y >= 1 && y <= n &&
          a[x][y] + d[p.ft][p.sd] < d[x][y]) {
        q.push_back({x, y});
        d[x][y] = a[x][y] + d[p.ft][p.sd];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"taxe.in"};
  ofstream cout{"taxe.out"};

  int k, n;
  cin >> k >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      d[i][j] = 1e9;
    }
  }

  bfs(1, 1, n);
  if (k - d[n][n] < 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << k - d[n][n] << endl;

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << d[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}