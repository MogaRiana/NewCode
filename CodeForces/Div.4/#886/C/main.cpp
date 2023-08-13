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
    vector<vector<char>> vv(8, vector<char>(8));

    pair<i64, i64> pos = {-1, -1};
    for (i64 i = 0; i < 8; i++) {
      for (i64 j = 0; j < 8; j++) {
        cin >> vv[i][j];

        if (pos.first == -1 and pos.second == -1 and vv[i][j] != '.') {
          pos = {i, j};
        }
      }
    }

    i64 jj = pos.second;
    for (i64 i = pos.first; i < 8; i++) {
      if (vv[i][jj] != '.') {
        cout << vv[i][jj];
      } else {
        break;
      }
    }

    cout << endl;
  }

  return 0;
}
