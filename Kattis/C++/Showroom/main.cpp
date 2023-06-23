#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef vector<bool> vb;

const vi64 dirx = {-1, 1, 0, 0};
const vi64 diry = {0, 0, -1, 1};

i64 solve(vector<vector<char>> &grid, pair<i64, i64> start) {
  i64 l = grid.size();
  i64 c = grid.front().size();

  deque<pair<i64, i64>> q;
  i64 best = 1e9;
  vv d(l, vi64(c, 1e9));
  q.push_back(start);
  d[start.first][start.second] = 1;

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 x = cur.first + dirx[i];
      i64 y = cur.second + diry[i];

      if (x >= 0 and x < l and y >= 0 and y < c and grid[x][y] != '#' and
          d[x][y] >= 1e9) {
        if (grid[x][y] == 'c') {
          d[x][y] = d[cur.first][cur.second] + 1;
          q.push_back({x, y});
        } else {
          d[x][y] = d[cur.first][cur.second];
          q.push_front({x, y});
          if (x == 0 || x == l - 1 || y == 0 || y == c - 1) {
            best = min(best, d[x][y]);
          }
        }
      }
    }
  }

  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vector<vector<char>> grid(l, vector<char>(c));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  i64 x, y;
  cin >> x >> y;

  cout << solve(grid, {x - 1, y - 1}) << endl;

  return 0;
}