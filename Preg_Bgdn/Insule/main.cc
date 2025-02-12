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

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, a[101][101];
int n, m;
int res[4];

void fill(int i, int j, int x, int c) {
  if (i > 0 && j > 0 && i <= n && j <= m && a[i][j] == x) {
    a[i][j] = c;
    for (int k = 0; k < 4; ++k) {
      fill(i + dx[k], j + dy[k], x, c);
    }
  }
}

int okay(int i, int j, int v) {
  for (int k = 0; k < 4; ++k) {
    if (a[i + dx[k]][j + dy[k]] == v) {
      return 1;
    }
  }

  return 0;
}

int bfs() {
  deque<p64> q;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0 && okay(i, j, -1)) {
        a[i][j] = 1;
        q.push_back({i, j});
      }
    }
  }

  while (!q.empty()) {
    int i = q.front().ft, j = q.front().sd;
    q.pop_front();

    for (int k = 0; k < 4; k++) {
      int ii = i + dx[k], jj = j + dy[k];
      if (ii > 0 && ii <= n && jj > 0 && jj <= m && a[ii][jj] == 0) {
        a[ii][jj] = a[i][j] + 1;
        q.push_back({ii, jj});

        if (okay(ii, jj, -2)) {
          return a[ii][jj];
        }
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"insule.in"};
  ofstream cout{"insule.out"};

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] > 0) {
        res[a[i][j]]++;
        fill(i, j, a[i][j], -a[i][j]);
      }
    }
  }

  cout << res[1] << " " << res[2] << " " << res[3] << " ";
  cout << bfs();

  return 0;
}