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
    i64 n;
    cin >> n;

    i64 crt = 0, res = -1;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;

      if (x == 0) {
        crt++;
      } else {
        res = max(crt, res);
        crt = 0;
      }
    }
    res = max(crt, res);

    cout << res << endl;
  }

  return 0;
}