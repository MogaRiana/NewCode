#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 tc;
  cin >> tc;
  while (tc--) {
    i64 n, x = 0, y = 0;
    string s;
    bool notfound = true;
    cin >> n >> s;

    for (i64 i = 0; i < n; i++) {
      if (s[i] == 'L') {
        x--;
        if (x == 1 && y == 1) {
          cout << "YES" << endl;
          notfound = false;
          break;
        }
      } else if (s[i] == 'R') {
        x++;
        if (x == 1 && y == 1) {
          cout << "YES" << endl;
          notfound = false;
          break;
        }
      } else if (s[i] == 'U') {
        y++;
        if (x == 1 && y == 1) {
          cout << "YES" << endl;
          notfound = false;
          break;
        }
      } else if (s[i] == 'D') {
        y--;
        if (x == 1 && y == 1) {
          cout << "YES" << endl;
          notfound = false;
          break;
        }
      }
    }

    if (notfound) {
      cout << "NO" << endl;
    }
  }

  return 0;
}