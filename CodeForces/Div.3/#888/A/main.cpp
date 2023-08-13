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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, m, k, h;
    cin >> n >> m >> k >> h;

    i64 crt = 0;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;

      bool ok = true;
      for (i64 j = 1; j <= m and ok; j++) {
        i64 pv = j;

        for (i64 jj = 1; jj <= m; jj++) {
          i64 s1, s2;
          s1 = abs(h - x);
          s2 = abs(jj - pv) * k;

          if (s1 == s2 and jj != j) {
            ok = false;
            break;
          }
        }
      }

      if (!ok) {
        crt++;
      }
    }

    cout << crt << endl;
  }

  return 0;
}
