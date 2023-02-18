#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

i64 gcd(i64 &a, i64 &b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}

i64 vlcm(vi64 &v, i64 &n) {
  i64 res = v[0];

  for (i64 i = 1; i < n; i++) {
    res = (res * v[i]) / gcd(v[i], res);
  }

  return res;
}

int main() {
  i64 t;
  cin >> t;

  for (i64 i = 0; i < t; i++) {
    i64 n;
    cin >> n;
    vi64 v(n);

    for (i64 j = 0; j < n; j++) {
      cin >> v[j];
    }

    if (vlcm(v, n) <= 1e9) {
      cout << vlcm(v, n) << endl;
    } else {
      cout << "More than a billion." << endl;
    }
  }

  return 0;
}