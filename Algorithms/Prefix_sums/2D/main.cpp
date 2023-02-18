#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  vv v = {{0, 0, 0, 0, 0, 0},
          {0, 1, 5, 6, 11, 8},
          {0, 1, 7, 11, 9, 4},
          {0, 4, 6, 1, 3, 2},
          {0, 7, 5, 4, 2, 3}};
  vv pref = v;
  i64 n = 5, m = 6;

  for (i64 i = 1; i < n; i++) {
    pref[i][0] += pref[i - 1][0];
  }
  for (i64 j = 1; j < m; j++) {
    pref[0][j] += pref[0][j - 1];
  }

  for (i64 i = 1; i < n; i++) {
    for (i64 j = 1; j < m; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + v[i][j];
    }
  }

  i64 x1, y1, x2, y2, res;
  while (cin >> x1 >> y1 >> x2 >> y2) {

    if (x1 && x2 && y1 && y2) {
      res = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
            pref[x1 - 1][y1 - 1];
    } else if (x1 == 0 && y1 == 0) {
      res = pref[x2][y2];
    } else if (y1 == 0) {
      res = pref[x2][y2] - pref[x1 - 1][y2];
    } else if (x1 == 0) {
      res = pref[x2][y2] - pref[x2][y1 - 1];
    }

    cout << res << endl;
  }

  return 0;
}