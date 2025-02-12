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

const int dirx[] = {0, 0, 1, -1};
const int diry[] = {1, -1, 0, 0};

int n, m;
int c;
char a[402][402];
int v[402][402];

int bfs(int i, int j, char col) {
  int crt = 0;
  queue<pair<int, int>> q;
  q.push({i, j});

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    v[p.first][p.second] = 1;
    crt++;

    for (int k = 0; k < 4; k++) {
      int x = p.first + dirx[k];
      int y = p.second + diry[k];

      if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == col &&
          v[x][y] == 0) {
        q.push({x, y});
        v[x][y] = 1;
      }
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"ferma.in"};
  ofstream cout{"ferma.out"};

  cin >> c >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == 0) {
        ans = max(ans, bfs(i, j, a[i][j]));
      }
    }
  }

  cout << ans << endl;

  return 0;
}