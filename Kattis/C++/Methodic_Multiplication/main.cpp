#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

str repet(str s, i64 n) {
  str ss;
  for (i64 i = 0; i < n; i++) {
    ss += s;
  }

  return ss;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str x, y;
  cin >> x >> y;

  i64 crtx = 0, crty = 0;
  for (i64 i = 0; i < x.size(); i++) {
    if (x[i] == 'S') {
      crtx++;
    }
  }

  for (i64 i = 0; i < y.size(); i++) {
    if (y[i] == 'S') {
      crty++;
    }
  }

  i64 res = crtx * crty;
  cout << repet("S(", res) << 0 << repet(")", res);

  return 0;
}