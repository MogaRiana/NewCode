#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;

const vi64 dirx = {1, -1, 0, 0};
const vi64 diry = {0, 0, 1, -1};

bool verify(i64 x, i64 y, p64 v) {
  if (x >= 0 and x < v.first and y >= 0 and y < v.second) {
    return true;
  }
  return false;
}

void dfs(vector<vector<char>> &v, vector<vector<bool>> &visit, p64 start) {
  i64 x1 = start.first;
  i64 y1 = start.second;
  p64 p = {v.size(), v.front().size()};

  for (i64 i = 0; i < 4; i++) {
    i64 xx = x1 + dirx[i];
    i64 yy = y1 + diry[i];
    if (verify(xx, yy, p) and (v[xx][yy] == 'L' or v[xx][yy] == 'C') and
        !visit[xx][yy]) {
      visit[xx][yy] = true;
      dfs(v, visit, {xx, yy});
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
          p64 start;
          start.first = i;
          start.second = j;
          dfs(v, visit, start);
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