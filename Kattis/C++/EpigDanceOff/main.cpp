#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 l, c;
  cin >> l >> c;

  vv v(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      char c;
      cin >> c;
      if (c == '$') {
        v[i][j] = 1;
      } else {
        v[i][j] = 0;
      }
    }
  }

  i64 crt = 0;
  for (i64 i = 0; i < c; i++) {
    bool ok = true;
    for (i64 j = 0; j < l; j++) {
      if (v[j][i] == 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      crt++;
    }
  }

  cout << crt + 1 << endl;

  return 0;
}