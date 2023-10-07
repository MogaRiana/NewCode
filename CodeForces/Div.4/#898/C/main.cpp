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
    i64 res = 0;
    for (i64 i = 0; i < 10; i++) {
      for (i64 j = 0; j < 10; j++) {
        char c;
        cin >> c;

        if (c == 'X') {
          if ((i == 0 and (j >= 0 and j < 10)) or
              (i == 9 and (j >= 0 and j < 10)) or
              (j == 0 and (i >= 0 and i < 10)) or
              (j == 9 and (i >= 0 and i < 10))) {
            res += 1;
          } else if ((i == 1 and (j >= 1 and j < 9)) or
                     (i == 8 and (j >= 1 and j < 9)) or
                     (j == 1 and (i >= 1 and i < 9)) or
                     (j == 8 and (i >= 1 and i < 9))) {
            res += 2;
          } else if ((i == 2 and (j >= 2 and j < 8)) or
                     (i == 7 and (j >= 2 and j < 8)) or
                     (j == 2 and (i >= 2 and i < 8)) or
                     (j == 7 and (i >= 2 and i < 8))) {
            res += 3;
          } else if ((i == 3 and (j >= 3 and j < 7)) or
                     (i == 6 and (j >= 3 and j < 7)) or
                     (j == 3 and (i >= 3 and i < 7)) or
                     (j == 6 and (i >= 3 and i < 7))) {
            res += 4;
          } else if ((i == 4 and (j >= 4 and j < 6)) or
                     (i == 5 and (j >= 4 and j < 6)) or
                     (j == 4 and (i >= 4 and i < 6)) or
                     (j == 5 and (i >= 4 and i < 6))) {
            res += 5;
          }
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
