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

void bfs(vv &grid, pair<i64, i64> start, vv &d) {
  deque<pair<i64, i64>> q;
  vector<vb> visit(grid.size(), vb(grid.front().size(), false));
  q.push_back(start);
  visit[start.first][start.second] = true;

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();

    i64 val = grid[cur.first][cur.second];
    i64 x = cur.first;
    i64 y = cur.second;

    for (int i = 0; i < 4; i++) {
      i64 xx = x + (dirx[i] * val);
      i64 yy = y + (diry[i] * val);

      if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid.front().size() &&
          !visit[xx][yy]) {
        visit[xx][yy] = true;
        q.push_back({xx, yy});
        d[xx][yy] = min(1 + d[x][y], d[xx][yy]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vv grid(l, vi64(c));
  vv d(l, vi64(c, 1e9));
  d[0][0] = 0;
  for (i64 i = 0; i < l; i++) {
    str s;
    cin >> s;
    for (i64 j = 0; j < c; j++) {
      grid[i][j] = s[j] - '0';
    }
  }

  bfs(grid, {0, 0}, d);
  if (d[l - 1][c - 1] == 1e9) {
    cout << -1 << endl;
  } else {
    cout << d[l - 1][c - 1] << endl;
  }

  return 0;
}