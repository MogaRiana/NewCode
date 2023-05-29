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

void bfs(vector<vector<char>> &grid, pair<i64, i64> start) {
  i64 crt = 0;
  deque<pair<i64, i64>> q;
  q.push_back(start);
  vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    vector<pair<i64, i64>> pos;
    q.pop_front();
    visit[cur.first][cur.second] = true;

    if (grid[cur.first][cur.second] == 'G') {
      crt++;
      grid[cur.first][cur.second] = '.';
    }

    for (i64 i = 0; i < 4; i++) {
      i64 x = cur.first + dirx[i];
      i64 y = cur.second + diry[i];

      if (x >= 0 and x < grid.size() and y >= 0 and y < grid.front().size() and
          !visit[x][y] and grid[x][y] != '#') {
        if (grid[x][y] != 'T') {
          pos.push_back({x, y});
          visit[x][y] = true;
        } else {
          pos.clear();
          break;
        }
      }
    }

    for (i64 i = 0; i < pos.size(); i++) {
      q.push_back(pos[i]);
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