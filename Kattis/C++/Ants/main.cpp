#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 l, n;
    cin >> l >> n;

    i64 res1 = 0, res2 = 0;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;

      if (x < l / 2) {
        res1 = max(res1, x);
        res2 = max(res2, l - x);
      } else if (x > l / 2) {
        res1 = max(res1, l - x);
        res2 = max(res2, x);
      } else {
        res1 = max(res1, x);
        res2 = max(res2, x = 1);
      }
    }

    cout << res1 << " " << res2 << endl;
  }

  return 0;
}