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
    i64 n, c;
    cin >> n >> c;

    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    i64 l = 0, r = 1e5;
    while (l <= r) {
      i64 mid = l + (r - l) / 2;

      i64 sum = 0;
      for (i64 i = 0; i < n; i++) {
        i64 cc = pow((2 * mid + v[i]), 2);
        sum += cc;
      }

      if (sum == c) {
        cout << mid << endl;
        break;
      } else if (sum < c and sum >= 0) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }

  return 0;
}