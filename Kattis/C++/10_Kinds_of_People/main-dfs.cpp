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

bool verify(i64 x, i64 y, pair<i64, i64> v) {
  if (x >= 0 and x < v.first and y >= 0 and y < v.second) {
    return true;
  }
  return false;
}

void dfs(pair<i64, i64> start, vv &v, vector<vector<bool>> &visit) {
  i64 x1 = start.first;
  i64 y1 = start.second;
  pair<i64, i64> p = {v.size(), v.front().size()};

  for (i64 i = 0; i < 4; i++) {
    i64 xx = x1 + dirx[i];
    i64 yy = y1 + diry[i];

    if (verify(xx, yy, p) and v[xx][yy] == v[x1][y1] and !visit[xx][yy]) {
      visit[xx][yy] = true;
      dfs({xx, yy}, v, visit);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vv v(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    str s;
    cin >> s;
    for (i64 j = 0; j < c; j++) {
      v[i][j] = s[j] - '0';
    }
  }

  i64 n;
  cin >> n;
  while (n--) {
    vector<vector<bool>> visit(l, vector<bool>(c, false));
    pair<i64, i64> start;
    pair<i64, i64> endd;

    cin >> start.first >> start.second >> endd.first >> endd.second;
    start.first--;
    start.second--;
    endd.first--;
    endd.second--;

    dfs(start, v, visit);

    if (visit[endd.first][endd.second]) {
      if (v[start.first][start.second] == 0) {
        cout << "binary" << endl;
      } else {
        cout << "decimal" << endl;
      }
    } else {
      cout << "neither" << endl;
    }
  }

  return 0;
}