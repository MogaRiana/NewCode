#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef pair<i64, i64> p64;

i64 l, c;
vector<vector<i64>> v;

i64 sum(p64 x, p64 y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

i64 s = 0;
void f(p64 x, p64 p) {
  i64 i = x.first, j = x.second;
  i64 p1 = p.first, p2 = p.second;

  s += (sum(x, p) * v[p1][p2]);

  if (p1 == l - 1 and p2 == c - 1) {
    return;
  }
  if (p2 < c - 1) {
    f(x, {p1, p2 + 1});
  } else if (p2 == c - 1 and p1 < l - 1) {
    f(x, {p1 + 1, 0});
  }
}

int main() {
  cin >> l >> c;

  v.resize(l, vector<i64>(c));

  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  i64 res = 1e9;
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      s = 0;
      f({i, j}, {0, 0});
      res = min(res, s);
    }
  }

  cout << res << endl;

  return 0;
}
