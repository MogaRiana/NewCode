#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool verify(vv &grid) {
  bool ok = false;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid.front().size(); j++) {
      if (grid[i][j] == 0) {
        ok = true;
      } else if (grid[i][j] == 1) {
        grid[i][j]++;
      }
    }
  }

  if (ok) {
    return true;
  }

  return false;
}

const vi64 dirx = {-1, 1, 0, 0};
const vi64 diry = {0, 0, -1, 1};

void bfs(vv &grid, pair<i64, i64> start) {
  for (i64 i = 0; i < 4; i++) {
    i64 x = start.first + dirx[i];
    i64 y = start.second + diry[i];
    if (x >= 0 and x < grid.size() and y >= 0 and y < grid.front().size() and
        grid[x][y] == 0) {
      grid[x][y]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c, n;
  cin >> l >> c >> n;

  vv grid(l, vi64(c, 0));
  for (i64 i = 0; i < n; i++) {
    i64 x, y;
    cin >> x >> y;
    grid[x - 1][y - 1] = 2;
  }

  i64 crt = 1;
  while (verify(grid)) {
    crt++;

    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        if (grid[i][j] == 2) {
          bfs(grid, {i, j});
        }
      }
    }
  }

  cout << crt << endl;

  return 0;
}