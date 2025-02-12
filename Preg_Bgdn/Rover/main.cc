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

const int NMAX = 502;
int a[NMAX][NMAX];
int d[NMAX][NMAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool okay = false;
int c;

void bfs(int i, int j, int n, int g) {
  deque<pair<int, int>> q;
  q.push_back({i, j});
  d[i][j] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop_front();

    for (int k = 0; k < 4; k++) {
      int x = p.first + dx[k];
      int y = p.second + dy[k];

      if (d[x][y] == -1) {
        if (a[x][y] >= g) {
          d[x][y] = d[p.first][p.second];
          q.push_front({x, y});
        } else {
          d[x][y] = d[p.first][p.second] + 1;
          q.push_back({x, y});

          if (c == 2) {
            okay = true;
            return;
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"rover.in"};
  ofstream cout{"rover.out"};

  int g;
  int n;
  cin >> c >> n;

  if (c == 1) {
    cin >> g;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      d[i][j] = -1;
    }
  }

  if (c == 1) {
    bfs(1, 1, n, g);
    cout << d[n][n] << endl;

    return 0;
  }

  int l = 0, r = 10001;
  int res = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    bfs(1, 1, n, mid);
    if (okay) {
      r = mid - 1;
    } else {
      res = mid;
      l = mid + 1;
    }
  }

  cout << res << endl;

  return 0;
}