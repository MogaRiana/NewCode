#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vi64 dirx = {1, -1, 0, 0};
const vi64 diry = {0, 0, 1, -1};
i64 l, c;

void bfs(vector<vector<char>> &v, vector<vector<bool>> &visit, i64 x, i64 y) {
  deque<pair<i64, i64>> q;
  q.push_back({x, y});

  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();
    visit[p.first][p.second] = true;

    for (i64 i = 0; i < 4; i++) {
      i64 xx = p.first + dirx[i];
      i64 yy = p.second + diry[i];

      if (xx >= 0 and xx < l and yy >= 0 and yy < c and !visit[xx][yy] and
          v[xx][yy] == '.') {
        q.push_back({xx, yy});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  cin >> l >> c;
  vector<vector<char>> v(l, vector<char>(c));

  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  vector<vector<bool>> visit(l, vector<bool>(c, false));

  i64 crt = 0;
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] == '.' and !visit[i][j]) {
        bfs(v, visit, i, j);
        crt++;
      }
    }
  }

  cout << crt << endl;

  return 0;
}