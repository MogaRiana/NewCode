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
  i64 crt = 0, sp = 0;
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
      if (v[i][j] % 2 == 1) {
        crt++;
      } else {
        sp += v[i][j];
      }
    }
  }

  cout << endl;

  for (i64 i = 1; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  i64 sum = 0;
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < i; j++) {
      sum += v[i][j];
    }
  }

  cout << sum << endl;

  return 0;
}