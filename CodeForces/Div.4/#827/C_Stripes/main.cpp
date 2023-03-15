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

  i64 t;
  cin >> t;
  while (t--) {
    vector<vector<char>> v(8, vector<char>(8));
    for (i64 i = 0; i < 8; i++) {
      for (i64 j = 0; j < 8; j++) {
        cin >> v[i][j];
      }
    }

    bool ok = true, red = false;
    for (i64 i = 0; i < 8 && ok; i++) {
      i64 crt = 0;
      for (i64 j = 0; j < 7; j++) {
        if (v[i][j] == 'R' && v[i][j + 1] == 'R') { // r
          crt++;
        }
      }

      if (crt == 7) {
        red = true;
        break;
      }
    }

    if (red) {
      cout << "R" << endl;
    } else {
      cout << "B" << endl;
    }
  }
  return 0;
}