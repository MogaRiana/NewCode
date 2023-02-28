#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
#define endl '\n'

int main() {
  i64 n, t, crt = 0, a1, b1;
  cin >> n >> t >> a1 >> b1;
  if (b1 > t) {
    cout << t << endl;
    return 0;
  }

  i64 d = a1 + b1 - 1;
  crt = b1;
  n--;
  while (n--) {
    i64 a2, b2;
    cin >> a2 >> b2;
    if (a2 > d) {
      if (crt + b2 <= t) {
        crt += b2;
      } else {
        crt += t - a2 + 1;
      }
      b1 = b2;
    }
    a1 = a2;
    d = a1 + b1 - 1;
  }

  cout << crt << endl;

  return 0;
}