#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 n, m, q, s;

  while (cin >> n >> m >> q >> s) {
    if (n == 0 and m == 0 and q == 0 and s == 0) {
      break;
    }

    vector<vector<pair<i64, i64>>> gg(n);
    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      gg[u].push_back({v, w});
    }

    for (i64 i = 0; i < q; i++) {
      i64 cc;
      cin >> cc;
    }
  }

  return 0;
}