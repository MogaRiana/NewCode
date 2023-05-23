#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vi64 dirx = {0, 0, 1, -1, -1, -1, 1, 1};
const vi64 diry = {1, -1, 0, -0, -1, 1, -1, 1};

bool bfs(vector<vector<char>> &eep, vector<vector<bool>> &visit,
         pair<i64, i64> start) {
  deque<pair<i64, i64>> q;
  q.push_back(start);

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    i64 crt = 0;
    vector<pair<i64, i64>> poz;
    for (int i = 0; i < 8; i++) {
      int x = cur.first + dirx[i];
      int y = cur.second + diry[i];
      if (x >= 0 and x < eep.size() and y >= 0 and y < eep.front().size() and
          eep[x][y] == '#') {
        crt++;
        poz.push_back({x, y});
      }
    }

    if (crt == 2) {
      for (i64 i = 0; i < poz.size(); i++) {
        if (!visit[poz[i].first][poz[i].second]) {
          q.push_back(poz[i]);
        }
      }
    } else {
      return false;
    }
  }

  return true;
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

  i64 crt = 0;
  vector<vector<bool>> visit(l, vector<bool>(c, false));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (grid[i][j] == '#' and !visit[i][j]) {
        pair<i64, i64> start = {i, j};

        if (bfs(grid, visit, start)) {
          crt++;
        }
      }
    }
  }

  cout << crt << endl;

  return 0;
}