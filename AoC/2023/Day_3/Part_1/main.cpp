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

const vi64 dirx = {0, 0, 1, -1, -1, -1, 1, 1};
const vi64 diry = {1, -1, 0, -0, -1, 1, -1, 1};

bool verify(i64 x, i64 y, vector<str> &v) {
  if (x >= 0 and x < v.size() and y >= 0 and y < v.front().size()) {
    return true;
  }
  return false;
}

bool ver(vector<str> &v, pair<p64, p64> pos) {
  i64 i = pos.first.first;
  i64 fj = pos.first.second, sj = pos.second.second;

  for (i64 j = fj; j < sj; j++) {
    for (i64 k = 0; k < 8; k++) {
      i64 x = i + dirx[k];
      i64 y = j + diry[k];
      if (verify(x, y, v)) {
        if (v[x][y] < '0' or v[x][y] > '9') {
          if (v[x][y] != '.') {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  vector<str> v;
  str s;
  while (cin >> s) {
    v.push_back(s);
  }

  i64 l = v.size(), c = v.front().size();
  i64 n = 0, sum = 0;
  p64 start = {0, 0};
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      if (v[i][j] >= '0' and v[i][j] <= '9') {
        if (n == 0) {
          n = v[i][j] - '0';
          start = {i, j};
        } else {
          n = n * 10 + v[i][j] - '0';
        }
      } else if (n) {
        if (ver(v, {start, {i, j}})) {
          sum += n;
        }
        n = 0;
        start = {0, 0};
      }
    }
  }

  cout << sum << endl;

  return 0;
}
