#include <algorithm>
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
typedef vector<p64> vp64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 x, y, r;
    cin >> x >> y;
    for (i64 i = 0; i < 3; i++) {
      i64 xx, yy;
      cin >> xx >> yy;
      if (xx == x) {
        r = abs(yy - y);
      }
    }

    cout << r * r << endl;
  }

  return 0;
}