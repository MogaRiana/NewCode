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
    i64 a, b, l;
    cin >> a >> b >> l;

    set<i64> div;
    for (i64 i = 1; i * i <= l; i++) {
      if (l % i == 0) {
        div.insert(i);
        div.insert(l / i);
      }
    }

    i64 res = 0;
    for (auto &x : div) {
      i64 n = l / x;

      while (n % a == 0) {
        n /= a;
      }
      while (n % b == 0) {
        n /= b;
      }

      if (n == 1) {
        res++;
      } else {
        i64 m = l / x;

        while (m % b == 0) {
          m /= b;
        }
        while (m % a == 0) {
          m /= a;
        }
        if (m == 1) {
          res++;
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
