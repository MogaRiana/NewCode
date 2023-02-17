#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, s = 0;
    cin >> n;
    i64 l = 0, r = n - 1;
    vi64 v(n);
    bool ok = true;
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
      s += v[i];
    }

    vi64 eep = v;

    while (ok) {
      ok = false;
      i64 sum = 0;

      if (r - l > 1) {
        v[l] = -v[l];
        v[r] = -v[r];
        l++;
        r--;
        for (i64 i = 0; i < n; i++) {
          sum += v[i];
        }

        if (sum > s) {
          s = sum;
        }

        for (i64 i = 0; i < n; i++) {
          if (eep[i] != v[i]) {
            ok = true;
            break;
          }
        }
      } else if (r - l == 1) {
        v[l] = -v[l];
        v[r] = -v[r];
        l = 0;
        r = n - 1;
        for (i64 i = 0; i < n; i++) {
          sum += v[i];
        }

        if (sum > s) {
          s = sum;
        }

        for (i64 i = 0; i < n; i++) {
          if (eep[i] != v[i]) {
            ok = true;
            break;
          }
        }
      } else if (r == l) {
        l = 0;
        v[l] = -v[l];
        v[r] = -v[r];
        r = n - 1;
        l++;
        for (i64 i = 0; i < n; i++) {
          sum += v[i];
        }

        if (sum > s) {
          s = sum;
        }

        for (i64 i = 0; i < n; i++) {
          if (eep[i] != v[i]) {
            ok = true;
            break;
          }
        }
      }

      // if (k < n - 1) {
      //   v[k] = -v[k];
      //   v[k + 1] = -v[k + 1];
      //   k++;
      // } else {
      //   k = 0;
      // }

      // for (i64 i = 0; i < n; i++) {
      //   sum += v[i];
      // }

      // if (sum > s) {
      //   s = sum;
      // } else {
      //   cout << s << endl;
      //   break;
      // }
    }

    cout << s << endl;
  }

  return 0;
}