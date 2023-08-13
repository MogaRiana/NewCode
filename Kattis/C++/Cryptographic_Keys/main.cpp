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

  i64 n;
  cin >> n;

  i64 p = 10, m = 0;
  for (i64 i = 2; i < 10; i++) {
    i64 crt = 0, a = n;

    while (a / i != 0) {
      if (a % 2 == 0) {
        crt++;
      } else {
        break;
      }

      a /= 2;
    }

    if (crt > m) {
      p = i;
      m = crt;
    }
  }

  cout << p << endl;

  return 0;
}