#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vi64 dirx = {0, 0, 1, -1};
vi64 diry = {1, -1, 0, 0};

void bfs(vector<vector<char>> &sky, vector<vector<bool>> &visit,
         pair<i64, i64> start) {
  deque<pair<i64, i64>> q;
  q.push_back(start);

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    q.pop_front();
    visit[cur.first][cur.second] = true;

    for (i64 k = 0; k < 4; k++) {
      i64 xx = cur.first + dirx[k];
      i64 yy = cur.second + diry[k];

      if (xx >= 0 and xx < sky.size() and yy >= 0 and yy < sky[0].size() and
          sky[xx][yy] == '-' and !visit[xx][yy]) {
        visit[xx][yy] = true;
        q.push_back({xx, yy});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  i64 tt = 0;
  while (cin >> l >> c) {
    tt++;

    vector<vector<char>> sky(l, vector<char>(c));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        cin >> sky[i][j];
      }
    }

    i64 res = 0;
    vector<vector<bool>> visit(l, vector<bool>(c, false));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        if (sky[i][j] == '-' && !visit[i][j]) {
          res++;
          visit[i][j] = true;
          pair<i64, i64> start = {i, j};
          bfs(sky, visit, start);
        }
      }
    }

    cout << "Case " << tt << ": " << res << endl;
  }

  return 0;
}