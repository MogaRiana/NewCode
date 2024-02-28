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
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 sum = 0;
    vi64 v(n);
    for (auto &i : v) {
      cin >> i;
      sum += i;
    }

    if (sum == 1 or sum == 2) {
      cout << 1 << endl;
      continue;
    }
    if (sum % 3 == 0) {
      cout << 0 << endl;
    } else if (sum % 3 == 2) {
      cout << 1 << endl;
    } else {
      i64 crt = 1e9;
      bool ok = true;

      for (auto &i : v) {
        if ((sum - i) % 3 == 0) {
          crt = min(crt, i64(1));
          ok = false;
          break;
        } else if ((sum - i) % 3 == 2) {
          crt = min(crt, i64(2));
          ok = false;
        }
      }

      if (ok) {
        cout << 2 << endl;
      } else {
        cout << crt << endl;
      }
    }
  }

  return 0;
}
