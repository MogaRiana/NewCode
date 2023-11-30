#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

bool verify(i64 x, i64 y, pair<i64, i64> v) {
  if (x >= 0 and x < v.first and y >= 0 and y < v.second) {
    return true;
  }
  return false;
}

void bfs(vector<vector<char>> &grid, pair<i64, i64> start) {
  i64 crt = 0;
  deque<pair<i64, i64>> q;
  q.push_back(start);
  vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    if (grid[cur.first][cur.second] == 'G') {
      crt++;
      grid[cur.first][cur.second] = '.';
    }

    bool trap = false;
    for (i64 i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];

      if (verify(x, y, {grid.size(), grid[0].size()}) and grid[x][y] != '#' and
          !visit[x][y]) {
        if (grid[x][y] == 'T') {
          trap = true;
          break;
        }
      }
    }

    if (!trap) {
      for (i64 i = 0; i < 4; i++) {
        int x = cur.first + dirx[i];
        int y = cur.second + diry[i];

        if (verify(x, y, {grid.size(), grid[0].size()}) and
            grid[x][y] != '#' and !visit[x][y]) {
          q.push_back({x, y});
        }
      }
    } else {
      for (i64 i = 0; i < 4; i++) {
        int x = cur.first + dirx[i];
        int y = cur.second + diry[i];

        if (verify(x, y, {grid.size(), grid[0].size()})) {
          visit[x][y] = true;
        }
      }
    }
  }

  cout << crt << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> c >> l;

  vector<vector<char>> grid(l, vector<char>(c));
  pair<i64, i64> start;
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == 'P') {
        start = {i, j};
      }
    }
  }

  bfs(grid, start);

  return 0;
}