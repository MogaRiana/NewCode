#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 s, c, k;
  cin >> s >> c >> k;
  vi64 v(s);
  for (i64 i = 0; i < s; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  i64 crtt = 1, crtm = 1;

  for (i64 i = 1; i < s; i++) {
    if (abs(v[i] - v[i - 1]) <= k) {
      crtt++;
      if (crtt > c) {
        crtm++;
        crtt = 1;
      }
    } else {
      crtm++;
      crtt = 1;
    }
  }

  cout << crtm << endl;

  return 0;
}