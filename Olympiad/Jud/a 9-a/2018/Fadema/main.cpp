#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

bool corners(vector<vector<i32>> &ok, vector<vector<i32>> &v, i32 l, i32 i,
             i32 j, i32 k) {
  bool cool1 = false, cool2 = false, cool3 = false, cool4 = false;

  if (j - i > 0 && k - l > 0) {
    // up-left-corner
    if (v[l][i] != v[l + 1][i]) {
      ok[l][i]++;
    }
    if (v[l][i] != v[l][i + 1]) {
      ok[l][i]++;
    }
    if (ok[l][i] == 2) {
      cool1 = true;
    } else {
      cool1 = false;
    }

    // up-right-corner
    if (v[l][j] != v[l + 1][j]) {
      ok[l][j]++;
    }
    if (v[l][j] != v[l][j - 1]) {
      ok[l][j]++;
    }
    if (ok[l][j] == 2) {
      cool2 = true;
    } else {
      cool2 = false;
    }

    // down-left-corner
    if (v[k][i] != v[k - 1][i]) {
      ok[k][i]++;
    }
    if (v[k][i] != v[k][i + 1]) {
      ok[k][i]++;
    }
    if (ok[k][i] == 2) {
      cool3 = true;
    } else {
      cool3 = false;
    }

    // down-right-corner
    if (v[k][j] != v[k - 1][j]) {
      ok[k][j]++;
    }
    if (v[k][j] != v[k][j - 1]) {
      ok[k][j]++;
    }
    if (ok[k][j] == 2) {
      cool4 = true;
    } else {
      cool4 = false;
    }
  } else if (j - i > 0 && k - l == 0) {
    cool3 = true;
    cool4 = true;

    // up-left-corner
    if (v[l][i] != v[l][i + 1]) {
      ok[l][i]++;
    }
    if (ok[l][i] == 1) {
      cool1 = true;
    } else {
      cool1 = false;
    }

    // up-right-corner
    if (v[l][j] != v[l][j - 1]) {
      ok[l][j]++;
    }
    if (ok[l][j] == 1) {
      cool2 = true;
    } else {
      cool2 = false;
    }
  } else if (j - i == 0 && k - l > 0) {
    cool2 = true;
    cool4 = true;

    // up-left-corner
    if (v[l][i] != v[l + 1][i]) {
      ok[l][i]++;
    }
    if (ok[l][i] == 1) {
      cool1 = true;
    } else {
      cool1 = false;
    }
    // down-left-corner
    if (v[k][i] != v[k - 1][i]) {
      ok[k][i]++;
    }
    if (ok[k][i] == 1) {
      cool3 = true;
    } else {
      cool3 = false;
    }
  }

  if (cool1 && cool2 && cool3 && cool4) {
    return true;
  } else {
    return false;
  }
}

bool sides(vector<vector<i32>> &ok, vector<vector<i32>> &v, i32 l, i32 i, i32 j,
           i32 k) {
  bool cool1 = false, cool2 = false, cool3 = false, cool4 = false;

  if (j - i > 1 && k - l > 1) {
    // up-side
    for (i16 x = i + 1; x < j - 1; x++) {
      if (v[l][x] != v[l][x - 1]) {
        ok[l][x]++;
      }
      if (v[l][x] != v[l][x + 1]) {
        ok[l][x]++;
      }
      if (v[l][x] != v[l + 1][x]) {
        ok[l][x]++;
      }

      if (ok[l][x] == 3) {
        cool1 = true;
      } else {
        cool1 = false;
        break;
      }
    }
    // down-side
    for (i16 x = i + 1; x < j - 1; x++) {
      if (v[k][x] != v[k][x - 1]) {
        ok[k][x]++;
      }
      if (v[k][x] != v[k][x + 1]) {
        ok[k][x]++;
      }
      if (v[k][x] != v[k - 1][x]) {
        ok[k][x]++;
      }

      if (ok[k][x] == 3) {
        cool2 = true;
      } else {
        cool2 = false;
        break;
      }
    }
    // left-side
    for (i16 x = l + 1; x < k - 1; x++) {
      if (v[x][i] != v[x - 1][i]) {
        ok[x][i]++;
      }
      if (v[x][i] != v[x + 1][i]) {
        ok[x][i]++;
      }
      if (v[x][i] != v[x][i + 1]) {
        ok[x][i]++;
      }

      if (ok[x][i] == 3) {
        cool3 = true;
      } else {
        cool3 = false;
        break;
      }
    }
    // right-side
    for (i16 x = l + 1; x < k - 1; x++) {
      if (v[x][j] != v[x - 1][j]) {
        ok[x][j]++;
      }
      if (v[x][j] != v[x + 1][j]) {
        ok[x][j]++;
      }
      if (v[x][j] != v[x][j - 1]) {
        ok[x][j]++;
      }

      if (ok[x][j] == 3) {
        cool4 = true;
      } else {
        cool4 = false;
        break;
      }
    }
  } else if (j - i > 1 && k - l <= 1) {
    cool2 = true;
    cool3 = true;
    cool4 = true;

    // up-side
    for (i16 x = i + 1; x < j - 1; x++) {
      if (v[l][x] != v[l][x - 1]) {
        ok[l][x]++;
      }
      if (v[l][x] != v[l][x + 1]) {
        ok[l][x]++;
      }

      if (ok[l][x] == 2) {
        cool1 = true;
      } else {
        cool1 = false;
        break;
      }
    }
  } else if (j - i <= 1 && k - l > 1) {
    cool1 = true;
    cool2 = true;
    cool4 = true;

    // left-side
    for (i16 x = l + 1; x < k - 1; x++) {
      if (v[x][i] != v[x - 1][i]) {
        ok[x][i]++;
      }
      if (v[x][i] != v[x + 1][i]) {
        ok[x][i]++;
      }

      if (ok[x][i] == 2) {
        cool3 = true;
      } else {
        cool3 = false;
        break;
      }
    }
  }

  if (cool1 && cool2 && cool3 && cool4) {
    return true;
  } else {
    return false;
  }
}

bool middle(vector<vector<i32>> &ok, vector<vector<i32>> &v, i32 l, i32 i,
            i32 j, i32 k) {
  bool cool = false;

  if (j - i > 1 && k - l > 1) {
    for (i16 x = l + 1; i < k - 1; x++) {
      for (i16 y = i + 1; y < j - 1; y++) {
        if (v[x][y] != v[x - 1][y]) {
          ok[x][y]++;
        }
        if (v[x][y] != v[x + 1][y]) {
          ok[x][y]++;
        }
        if (v[x][y] != v[x][y + 1]) {
          ok[x][y]++;
        }
        if (v[x][y] != v[x][y - 1]) {
          ok[x][y]++;
        }

        if (ok[x][y] == 4) {
          cool = true;
        } else {
          cool = false;
          break;
        }
      }

      if (!cool) {
        break;
      }
    }
  }

  if (cool) {
    return true;
  } else {
    return false;
  }
}

vector<vector<i32>> pref_sum(vector<vector<i32>> &pref, i32 n, i32 m) {
  for (i64 i = 1; i < n; i++) {
    pref[i][0] += pref[i - 1][0];
  }
  for (i64 j = 1; j < m; j++) {
    pref[0][j] += pref[0][j - 1];
  }

  for (i64 i = 1; i < n; i++) {
    for (i64 j = 1; j < m; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];
    }
  }

  return pref;
}

bool verify(vector<vector<i32>> &v, i32 l, i32 i, i32 j, i32 k) {
  vector<vector<i32>> ok(k + 1, vector<i32>(j - i + 1, 0));
  if (corners(ok, v, l, i, j, k) && sides(ok, v, l, i, j, k) &&
      middle(ok, v, l, i, j, k)) {
    return true;
  } else {
    return false;
  }
}

void solve(vector<vector<i32>> &pref, vector<vector<i32>> &v, i32 n, i32 m) {
  ofstream cout{"fadema.out"};
  pref = pref_sum(v, n, m);
  i64 res = 1;

  for (i32 l = 0; l < n; l++) {
    for (i32 i = 0; i < m; i++) {
      bool stop = false;
      for (i32 j = i; j < m; j++) {
        for (i32 k = l; k < n; k++) {
          if (i == 0 && l == 0) {
            i64 s = pref[k][j];
            if ((s == 1 || s == -1 || s == 0) &&
                ((k != l && i == j) || (k == l && i != j) ||
                 (k != l && i != j))) {
              if (verify(v, l, i, j, k)) {
                i16 a = j - i + 1, b = k - l + 1;
                i64 size_vec = a * b;
                res = max(res, size_vec);
              } else {
                stop = true;
                break;
              }
            }
          } else if (l == 0 && i != 0) {
            i64 s = pref[k][j] - pref[k][i - 1];
            if ((s == 1 || s == -1 || s == 0) &&
                ((k != l && i == j) || (k == l && i != j) ||
                 (k != l && i != j))) {
              if (verify(v, l, i, j, k)) {
                i16 a = j - i + 1, b = k - l + 1;
                i64 size_vec = a * b;
                res = max(res, size_vec);
              } else {
                stop = true;
                break;
              }
            }
          } else if (l != 0 && i == 0) {
            i64 s = pref[k][j] - pref[l - 1][j];
            if ((s == 1 || s == -1 || s == 0) &&
                ((k != l && i == j) || (k == l && i != j) ||
                 (k != l && i != j))) {
              if (verify(v, l, i, j, k)) {
                i16 a = j - i + 1, b = k - l + 1;
                i64 size_vec = a * b;
                res = max(res, size_vec);
              } else {
                stop = true;
                break;
              }
            }
          } else if (l != 0 && i != 0) {
            i64 s = pref[k][j] - pref[l - 1][j] - pref[k][i - 1] +
                    pref[l - 1][i - 1];
            if ((s == 1 || s == -1 || s == 0) && (k != l && i != j)) {
              if (verify(v, l, i, j, k)) {
                i16 a = j - i + 1, b = k - l + 1;
                i64 size_vec = a * b;
                res = max(res, size_vec);
              } else {
                stop = true;
                break;
              }
            }
          }
        }

        if (stop) {
          break;
        }
      }
    }
  }

  cout << res << endl;
}

int main() {
  ifstream cin{"fadema.in"};

  i16 n, m;
  cin >> n >> m;
  vector<vector<i32>> v(n, vector<i32>(m));
  vector<vector<i32>> pref = v;

  for (i16 i = 0; i < n; i++) {
    for (i32 j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == 0) {
        v[i][j]--;
      }
    }
  }

  solve(pref, v, n, m);

  return 0;
}