#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vi64 v(6), resx, resy;
  i64 x, y;

  for (i64 i = 0; i < 6; i++) {
    cin >> v[i];
  }
  cin >> x >> y;

  while (next_permutation(v.begin(), v.end())) {
    if (v[0] + v[1] + v[2] == x and v[3] + v[4] + v[5] == y) {
      resx = {v[0], v[1], v[2]};
      resy = {v[3], v[4], v[5]};

      sort(resx.rbegin(), resx.rend());
      sort(resy.rbegin(), resy.rend());

      break;
    } else if (v[0] + v[1] + v[2] == y and v[3] + v[4] + v[5] == x) {
      resx = {v[3], v[4], v[5]};
      resy = {v[0], v[1], v[2]};

      sort(resx.rbegin(), resx.rend());
      sort(resy.rbegin(), resy.rend());

      break;
    }
  }

  for (i64 i = 0; i < 3; i++) {
    cout << resx[i] << " ";
  }
  for (i64 i = 0; i < 3; i++) {
    cout << resy[i] << " ";
  }

  return 0;
}