#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

const vi64 dirx = {0, 0, 1, -1};
const vi64 diry = {1, -1, 0, 0};

bool ver(i64 x, i64 y, i64 n) {
  if (x >= 0 and x < n and y >= 0 and y < n) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n));
    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }

    bool ok = true;
    for (i64 i = 0; i < n and ok; i++) {
      for (i64 j = 0; j < n and ok; j++) {
        if (v[i][j] == '1') {
          i64 crt = 0;
          for (i64 k = 0; k < 4; k++) {
            i64 x = i + dirx[k];
            i64 y = j + diry[k];
            if (ver(x, y, n) and v[x][y] == '1') {
              crt++;
            }
          }

          if (crt == 2) {
            cout << "SQUARE" << endl;
          } else {
            cout << "TRIANGLE" << endl;
          }

          ok = false;
        }
      }
    }
  }

  return 0;
}