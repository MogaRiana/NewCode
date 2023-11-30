#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 nextPerfectSquare(i64 N) {
  int nextN = floor(sqrt(N)) + 1;

  return nextN * nextN;
}

int main() {
  i64 n;
  cin >> n;

  while (n--) {
    i64 l;
    str s;
    cin >> s;

    if (ceil((double)sqrt(s.size())) == floor((double)sqrt(s.size()))) {
      l = s.size();
    } else {
      l = nextPerfectSquare(s.size());
    }

    i64 m = s.size(), r = sqrt(l);
    for (i64 i = 0; i < l - m; i++) {
      s.push_back('*');
    }

    vector<vector<char>> v(r, vector<char>(r));
    for (i64 i = 0; i < r; i++) {
      for (i64 j = 0; j < r; j++) {
        i64 k = i * r + j;
        v[i][j] = s[k];
      }
    }

    for (i64 j = 0; j < r; j++) {
      for (i64 i = r - 1; i >= 0; i--) {
        if (v[i][j] != '*') {
          cout << v[i][j];
        }
      }
    }

    cout << endl;
  }

  return 0;
}