#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i16 n, m;
  cin >> n >> m;
  vector<vector<i32>> v(n, vector<i32>(m));
  vector<vector<i32>> eep(n, vector<i32>(m));

  for (i16 i = 0; i < n; i++) {
    for (i32 j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  i16 x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1, x4 = -1, y4 = -1;

  for (i16 i = 0; i < m - 1; i++) {
    if (v[0][i] != v[0][i + 1]) {
      x2 = i;
      y2 = 0;
      if (x1 == -1) {
        x1 = i;
        y1 = 0;
      }
    } else if (v[0][i] == v[0][i + 1] && y1 != -1) {
      break;
    }
  }

  i32 k = 0;

  for (i16 i = 1; i < n; i++) {
    if (x1 != -1 && y1 != -1) {
      for (i16 j = x1; j < x2; j++) {
        if (v[i][j] != v[i - 1][j]) {
          y4 = i;
          x4 = j;
          if (x3 == -1) {
            x3 = j;
            y3 = i;
          }
        } else if (v[i][j] == v[i - 1][j] && y4 == -1) {
          y1 = j + 1;
        }
      }
    } else {
      k++;
      for (i16 j = 0; j < m - 1; j++) {
        if (v[k][j] != v[k][j + 1]) {
          y1 = j;
          if (x1 == -1) {
            x1 = j;
          }
        } else if (v[k][j] == v[k][j + 1] && y1 != -1) {
          break;
        }
      }
    }
  }

  i32 crt = 0;

  // for(i16 i = k; i <= )

  return 0;
}