#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
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

  i64 n;
  while (cin >> n) {
    i64 res = 1;
    i64 rem = 1;
    i64 crt = 1;

    if (n > 1) {
      while (rem != 0) {
        res += 1;
        crt = (crt * (10 % n)) % n;
        rem += crt;
        rem %= n;
      }
    }

    cout << res << endl;
  }

  return 0;
}