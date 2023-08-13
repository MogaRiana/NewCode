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
    i64 n, k;
    cin >> n >> k;

    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    i64 crt = 1, res = -1;

    for (i64 i = 1; i < n; i++) {
      if (v[i] - v[i - 1] <= k) {
        crt++;
      } else {
        if (crt > res) {
          res = crt;
        }
        crt = 1;
      }
    }

    if (crt > res) {
      res = crt;
    }

    if (res == -1) {
      cout << 0 << endl;
    } else {
      cout << n - res << endl;
    }
  }

  return 0;
}
