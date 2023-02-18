#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 n, m;
  cin >> n >> m;
  vi64 s(n), j(m);
  for (i64 i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (i64 i = 0; i < m; i++) {
    cin >> j[i];
  }

  sort(s.begin(), s.end());
  sort(j.begin(), j.end());

  vi64 c;

  for (i64 i = 0; i < m; i++) {
    i64 a = 1e9, l = 0, r = n - 1;

    while (l <= r) {
      i64 m = l + (r - l) / 2;

      if (s[m] >= j[i]) {
        a = min(a, s[m]);
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    c.push_back(a);
  }

  i64 crt = 0;

  for (i64 i = 0; i < m; i++) {
    crt += c[i] - j[i];
  }

  cout << crt << endl;

  return 0;
}