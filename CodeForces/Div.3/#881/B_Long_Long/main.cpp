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
    i64 n;
    cin >> n;

    i64 sum = 0, res = 0, crt = 0;
    bool ok = false;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;
      sum += abs(x);

      if (x <= 0) {
        if (x == 0 and ok) {
          ok = true;
        } else if (x < 0) {
          ok = true;
        }
      } else {
        if (ok) {
          ok = false;
          res++;
        }
      }
    }

    if (ok) {
      ok = false;
      res++;
    }

    cout << sum << " " << res << endl;
  }

  return 0;
}