#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<i32> vi32;
typedef vector<vi64> vv;
typedef vector<vector<i32>> vv32;
typedef string str;

const vi32 dirx = {-1, 1, 0, 0};
const vi32 diry = {0, 0, -1, 1};

bool verify(i32 &x, i32 &y, i32 &n) {
  if (x >= 0 and x < n and y >= 0 and y < n) {
    return true;
  }

  return false;
}

i32 solve1(vv32 &grid, i32 &n, i32 &g) {
  deque<pair<int, int>> q;
  q.push_back({0, 0});
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  vv32 mark(n, vi32(n, 1e9));
  mark[0][0] = 0;

  while (!q.empty()) {
    pair<i32, i32> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];

      if (verify(x, y, n)) {
        if (grid[x][y] >= g) {
          mark[x][y] = min(mark[x][y], mark[cur.first][cur.second]);
        } else {
          mark[x][y] = min(mark[x][y], mark[cur.first][cur.second] + 1);
        }
        if (!visit[x][y]) {
          q.push_back({x, y});
        }
      }
    }
  }

  return mark[n - 1][n - 1];
}

i32 solve2(vv32 &grid, i32 &n) {
  deque<pair<int, int>> q;
  q.push_back({0, 0});
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  vv32 mark(n, vi32(n, 0));
  mark[0][0] = grid[0][0];

  while (!q.empty()) {
    pair<i32, i32> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];

      if (verify(x, y, n)) {
        if (grid[x][y] >= mark[cur.first][cur.second]) {
          mark[x][y] = max(mark[x][y], mark[cur.first][cur.second]);
        } else {
          mark[x][y] = grid[x][y];
        }
        if (!visit[x][y]) {
          q.push_back({x, y});
        }
      }
    }
  }

  return mark[n - 1][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ifstream cin{"rover.in"};
  ofstream cout{"rover.out"};

  i32 c, n, g;
  cin >> c >> n;

  if (c == 1) {
    cin >> g;
  }

  vv32 grid(n, vi32(n));
  for (i32 i = 0; i < n; i++) {
    for (i32 j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  if (c == 1) {
    cout << solve1(grid, n, g) << endl;
  } else {
    g = grid[0][0];
    cout << solve2(grid, n) << endl;
  }

  return 0;
}