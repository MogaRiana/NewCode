#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool upl(vv &v, i64 i, i64 j) {
  if (v[i - 2][j - 1] || v[i - 1][j - 2]) {
    return true;
  } else {
    return false;
  }
}

bool upr(vv &v, i64 i, i64 j) {
  if (v[i - 2][j + 1] || v[i - 1][j + 2]) {
    return true;
  } else {
    return false;
  }
}

bool downl(vv &v, i64 i, i64 j) {
  if (v[i + 2][j - 1] || v[i + 1][j - 2]) {
    return true;
  } else {
    return false;
  }
}

bool downr(vv &v, i64 i, i64 j) {
  if (v[i + 2][j + 1] || v[i + 1][j + 2]) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vv v(9, vi64(9, 0));
  i64 crt = 0;

  for (i64 i = 2; i < 7; i++) {
    for (i64 j = 2; j < 7; j++) {
      char c;
      cin >> c;

      if (c == 'k') {
        v[i][j] = 1;
        crt++;
      } else {
        v[i][j] = 0;
      }
    }
  }

  if (crt == 9) {
    for (i64 i = 0; i < 5; i++) {
      for (i64 j = 0; j < 5; j++) {
        if (v[i][j]) {
          if (upl(v, i, j) || upr(v, i, j) || downl(v, i, j) ||
              downr(v, i, j)) {
            cout << "invalid" << endl;
            return 0;
          }
        }
      }
    }

    cout << "valid" << endl;
  } else {
    cout << "invalid" << endl;
  }
  return 0;
}