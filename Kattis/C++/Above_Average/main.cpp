#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<d64> vd64;

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    d64 n, m = 0, crt = 0;
    cin >> n;
    vd64 v(n);
    for (i64 j = 0; j < n; j++) {
      cin >> v[j];
      m += v[j];
    }
    m /= n;
    for (i64 j = 0; j < n; j++) {
      if (v[j] > m) {
        crt++;
      }
    }
    d64 p = crt * 100 / n;
    cout.precision(3);
    cout << fixed << p << "%" << endl;
  }
  return 0;
}