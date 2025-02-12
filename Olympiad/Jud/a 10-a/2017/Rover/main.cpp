#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const vector<int> dirx = {-1, 1, 0, 0};
const vector<int> diry = {0, 0, -1, 1};

bool verify(int x, int y, int n) {
  if (x >= 0 and x < n and y >= 0 and y < n) {
    return true;
  }

  return false;
}

int solve(vector<vector<int>> &grid, int n, int g, int c) {
  deque<pair<int, int>> q;
  q.push_back({0, 0});
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  vector<vector<int>> mark;

  if (c == 1) {
    mark.resize(n, vector<int>(n, 10000));
    mark[0][0] = 0;
  } else if (c == 2) {
    mark.resize(n, vector<int>(n, 0));
    mark[0][0] = grid[0][0];
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];

      if (verify(x, y, n)) {
        if (c == 1) {
          if (grid[x][y] >= g) {
            mark[x][y] = min(mark[x][y], mark[cur.first][cur.second]);
          } else {
            int cc = mark[cur.first][cur.second] + 1;
            mark[x][y] = min(mark[x][y], cc);
          }
          if (!visit[x][y]) {
            q.push_back({x, y});
          }
        } else if (c == 2) {
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
  }

  return mark[n - 1][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ifstream cin{"rover.in"};
  ofstream cout{"rover.out"};

  int c, n, g;
  cin >> c >> n;

  if (c == 1) {
    cin >> g;
  }

  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << solve(grid, n, g, c) << endl;

  return 0;
}