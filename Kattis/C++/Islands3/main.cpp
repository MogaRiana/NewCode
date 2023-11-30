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

void bfs(vector<vector<char>> &v, vector<vector<bool>> &visit,
         pair<i64, i64> start) {
  deque<pair<i64, i64>> q;
  q.push_back({start.first, start.second});

  while (!q.empty()) {
    pair<i64, i64> cur = q.front();
    visit[cur.first][cur.second] = true;
    q.pop_front();

    for (i64 i = 0; i < 4; i++) {
      i64 xx = cur.first + dirx[i];
      i64 yy = cur.second + diry[i];
      if (xx >= 0 and xx < v.size() and yy >= 0 and yy < v[0].size() and
          (v[xx][yy] == 'L' or v[xx][yy] == 'C') and !visit[xx][yy]) {
        q.push_back({xx, yy});
        visit[xx][yy] = true;
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
  vector<vector<char>> v(l, vector<char>(c));

  i64 crt = 0;
  bool land = false;
  for (i64 i = 0; i < l; ++i) {
    for (i64 j = 0; j < c; ++j) {
      cin >> v[i][j];
      if (v[i][j] == 'L') {
        land = true;
      }
    }
  }

  if (land) {
    vector<vector<bool>> visit(l, vector<bool>(c, false));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        if (v[i][j] == 'L' && !visit[i][j]) {
          pair<i64, i64> start;
          start.first = i;
          start.second = j;
          bfs(v, visit, start);
          crt++;
        }
      }
    }

    cout << crt << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}