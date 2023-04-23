#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vi64 dirx = {-1, -1, 0, 0, 1, 1};
vi64 diry = {-1, 1, -2, 2, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("input2.txt");
  ofstream cout("output2.txt");

  i64 n;
  cin >> n;
  n++;

  while (n--) {
    str s;
    vector<str> v;

    while (getline(cin, s)) {
      if (s == "") {
        break;
      }

      v.push_back(s);
    }

    i64 crt = 0;
    bool found = false;
    for (i64 i = 0; i < v.size(); i++) {
      for (i64 j = 0; j < v[0].size(); j++) {
        if (v[i][j] == 'W') {
          for (i64 k = 0; k < 6; k++) {
            i64 xx = i + dirx[k];
            i64 yy = j + diry[k];

            if (xx >= 0 && xx <= v.size() && yy >= 0 && yy <= v[0].size() &&
                v[xx][yy] == 'O') {
              crt++;
            }
          }

          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    cout << crt << endl;
  }

  return 0;
}