#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n, s, t;
  cin >> n;
  vi64 v(366, 0);

  for (i64 i = 0; i < n; i++) {
    cin >> s >> t;

    for (i64 j = s; j <= t; j++) {
      v[j]++;
    }
  }

  i64 crt = 0;

  for (i64 i = 1; i <= 365; i++) {
    if (v[i] >= 1) {
      crt++;
    }
  }

  cout << crt << endl;

  return 0;
}