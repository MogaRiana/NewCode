#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  //   ios::sync_with_stdio(false);
  //   cin.tie(NULL);

  i64 n, caz = 1;
  while (cin >> n) {
    cout << "Case " << caz << ":" << endl;
    caz++;

    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    i64 m;
    cin >> m;
    while (m--) {
      i64 a, res = v[0] + v[1];
      cin >> a;

      for (i64 i = 0; i < n; i++) {
        for (i64 j = i + 1; j < n; j++) {
          i64 s = v[i] + v[j];
          if (abs(a - s) < abs(a - res)) {
            res = s;
          }
        }
      }

      cout << "Closest sum to " << a << " is " << res << "." << endl;
    }
  }

  return 0;
}