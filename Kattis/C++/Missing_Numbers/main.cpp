#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n;
  bool ok = true;
  cin >> n;
  vi64 v(n);

  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (i64 i = 1; i <= v[n - 1]; i++) {
    i64 l = 0, r = n - 1;
    bool notfound = true;

    while (l <= r) {
      i64 m = l + ((r - l) / 2);
      if (v[m] == i) {
        notfound = false;
        break;
      } else if (v[m] > i) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    if (notfound) {
      cout << i << endl;
      ok = false;
    }
  }

  if (ok) {
    cout << "good job" << endl;
  }
  return 0;
}