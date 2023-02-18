#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n;
  cin >> n;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  vi64 pmx(n);
  pmx[0] = v[0];

  for (i64 i = 1; i < n; i++) {
    pmx[i] = max(pmx[i - 1], v[i]);
  }

  vi64 pmn(n);
  pmn[n - 1] = v[n - 1];

  for (i64 i = n - 2; i >= 0; i--) {
    pmn[i] = min(pmn[i + 1], v[i]);
  }

  i64 crt = 0;

  for (i64 i = 0; i < n; i++) {
    if (i > 0 && i < n - 1) {
      if (v[i] > pmx[i - 1] && v[i] <= pmn[i + 1]) {
        crt++;
      }
    } else if (i == 0) {
      if (v[i] <= pmn[i + 1]) {
        crt++;
      }
    } else if (i == n - 1) {
      if (v[i] > pmx[i - 1]) {
        crt++;
      }
    }
  }

  cout << crt << endl;

  return 0;
}