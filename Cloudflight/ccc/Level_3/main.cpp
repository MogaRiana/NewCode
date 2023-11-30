#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vi64 dirx = {1, -1, 0, 0};
vi64 diry = {0, 0, 1, -1};

bool verify(i64 x, i64 y, pair<i64, i64> v) {
  if (x >= 0 and x < v.first and y >= 0 and y < v.second) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("input2.txt");
  ofstream cout("output2.txt");

  i64 n;
  cin >> n;
  cin.ignore();

  vector<vector<str>> vv;

  while (n--) {
    str s;
    getline(cin, s);

    str v;
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] != ',' or s[i] != ' ') {
        v += s[i];
      }
    }

    vector<str> ss = {v};
    vv.push_back(ss);
  }

  for (i64 i = 0; i < vv.size(); i++) {
    for (i64 j = 0; j < vv.front().size(); j++) {
      str s = vv[i][j];
      for (i64 k = 0; k < 4; k++) {
        i64 x = i + dirx[k];
        i64 y = j + diry[k];

        if (x >= 0 and x < vv.size() && y >= 0 and y < vv.size()) {
          str ss = vv[x][y];
          if (s[0] == s[2]) {

          } else if (s[1] == s[3]) {
          }
        }
      }
    }
  }

  return 0;
}