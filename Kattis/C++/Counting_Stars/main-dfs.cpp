#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

const vi64 dirx = {1, -1, 0, 0};
const vi64 diry = {0, 0, 1, -1};

bool verify(i64 x, i64 y, vector<vi64> &v) {
  if (x >= 0 and x < v.size() and y >= 0 and y < v.front().size() and
      v[x][y] == 0) {
    return true;
  }
  return false;
}

void dfs(i64 i, i64 j, i64 col, vector<vi64> &v) {
  for (i64 d = 0; d < 4; d++) {
    i64 x = i + dirx[d];
    i64 y = j + diry[d];

    if (verify(x, y, v)) {
      v[x][y] = col;
      dfs(x, y, col, v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 a = 1;
  i64 l, c;
  while (cin >> l >> c) {
    vector<vi64> v(l, vi64(c));

    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        char c;
        cin >> c;
        if (c == '-') {
          v[i][j] = 0;
        } else {
          v[i][j] = -1;
        }
      }
    }

    i64 col = 0;
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        if (v[i][j] == 0) {
          dfs(i, j, ++col, v);
        }
      }
    }

    cout << "Case " << a++ << ": " << col << endl;
  }

  return 0;
}