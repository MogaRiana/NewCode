#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef string str;

int main() {
  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vi64 v(n);
    i64 cont = 0;
    for (auto &x : v) {
      cin >> x;
      cont += x;
    }

    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }

    cont /= n;
    i64 crtsm = 0;
    bool ok = true;
    for (i64 i = n - 1; i >= 0; i--) {
      if (v[i] != cont) {
        if (v[i] < cont) {
          crtsm += cont - v[i];
        } else if (v[i] > cont) {
          i64 dif = v[i] - cont;
          if (dif <= crtsm) {
            crtsm -= dif;
          } else {
            ok = false;
            break;
          }
        }
      }
    }

    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}