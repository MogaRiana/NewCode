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
const vi64 dirxx = {-1, 1};
const vi64 diryp = {-1, -1};
const vi64 diryi = {1, 1};

void bfs(vector<vector<char>> &v, vector<vector<bool>> &visit,
         pair<i64, i64> start, i64 honey, i64 &res) {
  deque<pair<i64, i64>> q;
  q.push_back({start.first, start.second});

  i64 crt = 1;
  while (!q.empty()) {
    i64 x = q.front().first;
    i64 y = q.front().second;
    visit[x][y] = true;
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 xx = x + dirx[i];
      i64 yy = y + diry[i];

      if (xx >= 0 and xx < v.size() and yy >= 0 and yy < v[0].size() and
          v[xx][yy] == '.' and !visit[xx][yy]) {
        visit[xx][yy] = true;
        crt++;
        q.push_back({xx, yy});
      }
    }

    if (start.first % 2 == 0) {
      for (i64 i = 0; i < 2; i++) {
        i64 xx = x + dirxx[i];
        i64 yy = y + diryp[i];

        if (xx >= 0 and xx < v.size() and yy >= 0 and yy < v[0].size() and
            v[xx][yy] == '.' and !visit[xx][yy]) {
          visit[xx][yy] = true;
          crt++;
          q.push_back({xx, yy});
        }
      }
    } else {
      for (i64 i = 0; i < 2; i++) {
        i64 xx = x + dirxx[i];
        i64 yy = y + diryi[i];

        if (xx >= 0 and xx < v.size() and yy >= 0 and yy < v[0].size() and
            v[xx][yy] == '.' and !visit[xx][yy]) {
          visit[xx][yy] = true;
          crt++;
          q.push_back({xx, yy});
        }
      }
    }
  }

  if (honey - crt) {
    honey -= crt;
    res++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 h, l, c;
  cin >> h >> l >> c;
  vector<vector<char>> v(l, vector<char>(c));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  i64 res = 0;
  vector<vector<bool>> visit(l, vector<bool>(c, false));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] == '.' && !visit[i][j]) {
        bfs(v, visit, {i, j}, h, res);
      }
    }
  }

  cout << res << endl;

  return 0;
}