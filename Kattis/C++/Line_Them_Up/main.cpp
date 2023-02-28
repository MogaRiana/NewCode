#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 make_num(str s) {
  i64 num = 0;

  for (i64 i = 0; i < s.size(); i++) {
    num += s[i] - 'A';
  }

  return num;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n;
  cin >> n;
  vector<str> v(n);

  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  bool c = false, d = false;
  for (i64 i = 0; i < n - 1; i++) {
    for (i64 j = 0; j < min(v[i].size(), v[i + 1].size()); j++) {
      if (v[i][j] < v[i + 1][j]) {
        c = true;
        break;
      } else if (v[i][j] > v[i + 1][j]) {
        d = true;
        break;
      }
    }
  }

  if (c && !d) {
    cout << "INCREASING" << endl;
  } else if (d && !c) {
    cout << "DECREASING" << endl;
  } else if (c && d) {
    cout << "NEITHER" << endl;
  }

  return 0;
}