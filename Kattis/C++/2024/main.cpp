#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

void cout_grid(vv &grid) {
  for (i64 i = 0; i < 4; i++) {
    for (i64 j = 0; j < 4; j++) {
      cout << grid[i][j] << " ";
    }

    cout << endl;
  }
}

void left(vv &grid) {
  for (i64 i = 0; i < 4; i++) {
    i64 nr = -1, posnr = -1;
    i64 pos0 = -1;
    for (i64 j = 0; j < 4; j++) {
      if (pos0 == -1 && grid[i][j] == 0) {
        pos0 = j;
      } else if (grid[i][j] != 0) {
        if (nr == -1) {
          posnr = j;
          nr = grid[i][j];
          if (pos0 != -1) {
            grid[i][pos0] = grid[i][j];
            grid[i][j] = 0;
            i64 aux = pos0;
            pos0 = j;
            j = posnr;
            posnr = aux;
          }
        } else {
          if (nr == grid[i][j]) {
            grid[i][posnr] *= 2;
            grid[i][j] = 0;
            j = posnr;
            posnr = -1;
            nr = -1;
          } else {
            nr = grid[i][j];
            posnr = j;

            if (pos0 != -1) {
              grid[i][pos0] = grid[i][j];
              grid[i][j] = 0;
              i64 aux = pos0;
              pos0 = j;
              j = posnr;
              posnr = aux;
            }
          }
        }
      }
    }
  }
}

void right(vv &grid) {
  for (i64 i = 0; i < 4; i++) {
    i64 nr = -1, posnr = -1;
    i64 pos0 = -1;
    for (i64 j = 3; j >= 0; j--) {
      if (pos0 == -1 && grid[i][j] == 0) {
        pos0 = j;
      } else if (grid[i][j] != 0) {
        if (nr == -1) {
          posnr = j;
          nr = grid[i][j];
          if (pos0 != -1) {
            grid[i][pos0] = grid[i][j];
            grid[i][j] = 0;
            i64 aux = pos0;
            pos0 = j;
            j = posnr;
            posnr = aux;
          }
        } else {
          if (nr == grid[i][j]) {
            grid[i][posnr] *= 2;
            grid[i][j] = 0;
            j = posnr;
            posnr = -1;
            nr = -1;
          } else {
            nr = grid[i][j];
            posnr = j;

            if (pos0 != -1) {
              grid[i][pos0] = grid[i][j];
              grid[i][j] = 0;
              i64 aux = pos0;
              pos0 = j;
              j = posnr;
              posnr = aux;
            }
          }
        }
      }
    }
  }
}

void up(vv &grid) {
  for (i64 i = 0; i < 4; i++) {
    i64 nr = -1, posnr = -1;
    i64 pos0 = -1;
    for (i64 j = 0; j < 4; j++) {
      if (pos0 == -1 && grid[j][i] == 0) {
        pos0 = j;
      } else if (grid[j][i] != 0) {
        if (nr == -1) {
          posnr = j;
          nr = grid[j][i];
          if (pos0 != -1) {
            grid[pos0][i] = grid[j][i];
            grid[j][i] = 0;
            i64 aux = pos0;
            pos0 = j;
            j = posnr;
            posnr = aux;
          }
        } else {
          if (nr == grid[j][i]) {
            grid[posnr][i] *= 2;
            grid[j][i] = 0;
            j = posnr;
            posnr = -1;
            nr = -1;
          } else {
            nr = grid[j][i];
            posnr = j;

            if (pos0 != -1) {
              grid[pos0][i] = grid[j][i];
              grid[j][i] = 0;
              i64 aux = pos0;
              pos0 = j;
              j = posnr;
              posnr = aux;
            }
          }
        }
      }
    }
  }
}

void down(vv &grid) {
  for (i64 i = 0; i < 4; i++) {
    i64 nr = -1, posnr = -1;
    i64 pos0 = -1;
    for (i64 j = 3; j >= 0; j--) {
      if (pos0 == -1 && grid[j][i] == 0) {
        pos0 = j;
      } else if (grid[j][i] != 0) {
        if (nr == -1) {
          posnr = j;
          nr = grid[j][i];
          if (pos0 != -1) {
            grid[pos0][i] = grid[j][i];
            grid[j][i] = 0;
            i64 aux = pos0;
            pos0 = j;
            j = posnr;
            posnr = aux;
          }
        } else {
          if (nr == grid[j][i]) {
            grid[posnr][i] *= 2;
            grid[j][i] = 0;
            j = posnr;
            posnr = -1;
            nr = -1;
          } else {
            nr = grid[j][i];
            posnr = j;

            if (pos0 != -1) {
              grid[pos0][i] = grid[j][i];
              grid[j][i] = 0;
              i64 aux = pos0;
              pos0 = j;
              j = posnr;
              posnr = aux;
            }
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vv grid(4, vi64(4));
  i64 t;

  for (i64 i = 0; i < 4; i++) {
    for (i64 j = 0; j < 4; j++) {
      cin >> grid[i][j];
    }
  }
  cin >> t;

  if (t == 0) {
    left(grid);
  } else if (t == 1) {
    up(grid);
  } else if (t == 2) {
    right(grid);
  } else if (t == 3) {
    down(grid);
  }

  cout_grid(grid);

  return 0;
}