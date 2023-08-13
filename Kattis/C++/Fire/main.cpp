#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vi64 dirx = {-1, 1, 0, 0};
const vi64 diry = {0, 0, -1, 1};
deque<pair<i64, i64>> fire_points;

void update(vector<vector<char>> &grid) {
  i64 l = grid.size(), c = grid.front().size();
  deque<pair<i64, i64>> q;
  q = fire_points;
  fire_points.clear();

  while (!q.empty()) {
    auto cur = q.front();
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 x = cur.first + dirx[i];
      i64 y = cur.second + diry[i];

      if (x >= 0 and x < l and y >= 0 and y < c and grid[x][y] == '.') {
        grid[x][y] = '*';
        fire_points.push_back({x, y});
      }
    }
  }
}

i64 solve(vector<vector<char>> &grid, pair<i64, i64> start) {
  i64 l = grid.size(), c = grid.front().size();
  vector<vector<bool>> visit(l, vector<bool>(c, false));
  vv steps(l, vi64(c, 1e9));
  steps[start.first][start.second] = 1;
  visit[start.first][start.second] = true;

  deque<pair<i64, i64>> p;
  p.push_back(start);

  while (!p.empty()) {
    deque<pair<i64, i64>> q = p;
    p.clear();

    while (!q.empty()) {
      pair<i64, i64> cur = q.front();
      q.pop_front();

      i64 xx = cur.first;
      i64 yy = cur.second;

      if ((xx == 0 or xx == l - 1 or yy == 0 or yy == c - 1) and
          grid[xx][yy] == '.') {
        return steps[xx][yy];
      }

      for (i64 i = 0; i < 4; i++) {
        i64 x = xx + dirx[i];
        i64 y = yy + diry[i];

        if (x >= 0 and x < l and y >= 0 and y < c and grid[x][y] == '.' and
            !visit[x][y]) {
          steps[x][y] = steps[xx][yy] + 1;
          p.push_back({x, y});
          visit[x][y] = true;
        }
      }
    }

    update(grid);
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 q;
  cin >> q;

  while (q--) {
    i64 l, c;
    cin >> c >> l;

    vector<vector<char>> grid(l, vector<char>(c, 0));
    pair<i64, i64> start;
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        cin >> grid[i][j];

        if (grid[i][j] == '*') {
          fire_points.push_back({i, j});
        } else if (grid[i][j] == '@') {
          start = {i, j};
          grid[i][j] = '.';
        }
      }
    }

    i64 res = solve(grid, start);
    fire_points.clear();

    if (res == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }

  return 0;
}