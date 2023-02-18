#include <bits/stdc++.h>

// #define endl '/n';
using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  ifstream cin{"tnia.in"};
  ofstream cout{"tnia.out"};

  i64 n, m, q;
  cin >> n >> m;

  vector<vector<i64>> pref(m, vector<i64>(n, 0));

  for (i64 i = 0; i < n; i++) {
    i64 h;
    cin >> h;

    for (i64 j = 0; j < h; j++) {
      pref[j][i] = 1;
    }
  }

  for (i64 i = 1; i < m; i++) {
    pref[i][0] += pref[i - 1][0];
  }
  for (i64 j = 1; j < n; j++) {
    pref[0][j] += pref[0][j - 1];
  }

  for (i64 i = 1; i < m; i++) {
    for (i64 j = 1; j < n; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];
    }
  }

  cin >> q;
  while (q--) {
    i64 x1, y1, x2, y2, res;
    cin >> y1 >> x1 >> y2 >> x2;

    x1--;
    x2--;
    y1--;
    y2--;

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