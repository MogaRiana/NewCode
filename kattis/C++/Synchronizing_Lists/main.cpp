#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    cout << endl;

    vi64 v1(n);
    vi64 v2(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v1[i];
    }
    for (i64 i = 0; i < n; i++) {
      cin >> v2[i];
    }

    vi64 suki1 = v1, suki2 = v2;
    vector<pair<i64, i64>> p;

    sort(suki1.begin(), suki1.end());
    sort(suki2.begin(), suki2.end());

    for (i64 i = 0; i < n; i++) {
      p.push_back({suki1[i], suki2[i]});
    }

    for (i64 i = 0; i < n; i++) {
      i64 l = 0, r = n - 1;

      while (l <= r) {
        i64 m = l + (r - l) / 2;

        if (p[m].first == v1[i]) {
          cout << p[m].second << endl;
          break;
        } else if (p[m].first > v1[i]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }

    cout << endl;
  }
  return 0;
}