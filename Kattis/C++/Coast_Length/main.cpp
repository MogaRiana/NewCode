#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vi64 dirx = {0, 0, -1, 1};
const vi64 diry = {-1, 1, 0, 0};

i64 count(vv &grid, pair<i64, i64> &cur) {
  i64 crt = 0;

  for (i64 i = 0; i < 4; i++) {
    i64 xx = cur.first + dirx[i];
    i64 yy = cur.second + diry[i];

    if (xx >= 0 and xx < grid.size() and yy >= 0 and
        yy < grid.front().size() and grid[xx][yy]) {
      crt++;
    }
  }

  return crt;
}

i64 bfs(vv &grid, pair<i64, i64> &start, vector<vector<bool>> &visit) {
  i64 crt = 0;
  bool ok = true;

  deque<pair<i64, i64>> q;
  q.push_back(start);

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (i64 i = 0; i < 4; i++) {
      i64 xx = cur.first + dirx[i];
      i64 yy = cur.second + diry[i];

      if (xx >= 0 and xx < grid.size() and yy >= 0 and
          yy < grid.front().size() and !grid[xx][yy] and !visit[xx][yy]) {
        q.push_back({xx, yy});
        visit[xx][yy] = true;
      } else if (xx >= 0 and xx < grid.size() and yy >= 0 and
                 yy < grid.front().size() and grid[xx][yy]) {
        crt++;
      } else if (xx < 0 or xx >= grid.size() or yy < 0 or
                 yy >= grid.front().size()) {
        ok = false;
      }
    }
  }

  if (ok) {
    return crt;
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vv grid(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    str ss;
    cin >> ss;

    for (i64 j = 0; j < c; j++) {
      grid[i][j] = ss[j] - '0';
    }
  }

  i64 res = 0;
  vector<vector<bool>> visit(l, vector<bool>(c, false));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (grid[i][j]) {
        pair<i64, i64> start = {i, j};
        res += 4 - count(grid, start);
      } else {
        if (!visit[i][j]) {
          pair<i64, i64> start = {i, j};
          res -= bfs(grid, start, visit);
        }
      }
    }
  }

  cout << res << endl;

  return 0;
}