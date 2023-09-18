#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool verify(vv &pp, i64 n) {
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      if (pp[i][j] != pp[n - j - 1][n - i - 1]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, v;
    cin >> n >> v;

    vv pp(v, vi64(v, 0));
    for (i64 i = 0; i < n; i++) {
      i64 k = v;
      if (i > 0) {
        cin >> k;
      }
      for (i64 j = v - 1; j >= v - k; j--) {
        pp[j][i] = 1;
      }
    }

    if (verify(pp, v)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}