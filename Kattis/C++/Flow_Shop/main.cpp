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

  vv v(l + 1, vi64(c + 1, 0));
  for (i64 i = 1; i <= l; i++) {
    for (i64 j = 1; j <= c; j++) {
      cin >> v[i][j];
    }
  }

  for (i64 i = 1; i <= l; i++) {
    for (i64 j = 1; j <= c; j++) {
      v[i][j] = max(v[i - 1][j], v[i][j - 1]) + v[i][j];
    }
  }

  for (i64 i = 1; i <= l; i++) {
    cout << v[i][c] << " ";
  }

  return 0;
}