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
    i64 n;
    str b, f;
    cin >> n >> b >> f;

    if (b == f) {
      cout << 0 << endl;
      continue;
    }

    i64 onesb = 0, onesf = 0, poscom = 0;
    for (i64 i = 0; i < n; i++) {
      if (b[i] == '1') {
        onesb++;
      }
      if (f[i] == '1') {
        onesf++;
      }
      if (b[i] == f[i] and b[i] == '1') {
        poscom++;
      }
    }

    if (!poscom) {
      if (onesb == 0) {
        cout << onesf << endl;
      } else if (onesf == onesb) {
        cout << onesf << endl;
      } else if (onesf > onesb) {
        cout << onesf - onesb << endl;
      } else if (onesf < onesb) {
        cout << onesb << endl;
      }
    } else {
      if (onesf >= onesb) {
        cout << onesf - poscom << endl;
      } else if (onesf < onesb) {
        cout << onesb - poscom << endl;
      }
    }
  }

  return 0;
}