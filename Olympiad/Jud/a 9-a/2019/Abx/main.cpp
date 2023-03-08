#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool verify(i64 x, i64 y) {
  double d = log(x) / log(y);
  if (d == ceil(d)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin{"abx.in"};
  ofstream cout{"abx.out"};

  i64 tc, m;
  cin >> tc >> m;

  while (tc--) {
    i64 nr;
    cin >> nr;

    i64 resmic;
    bool found = false;
    for (i64 i = nr; i > 0; i--) {
      for (i64 j = 2; j <= i; j++) {
        if (verify(i, j)) {
          resmic = i;
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    i64 resmare;
    found = false;
    for (i64 i = nr; i <= m; i++) {
      for (i64 j = 2; j <= i; j++) {
        if (verify(i, j)) {
          resmare = i;
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    if (abs(resmic - nr) < abs(resmare - nr)) {
      cout << resmic << endl;
    } else if (abs(resmic - nr) > abs(resmare - nr)) {
      cout << resmare << endl;
    } else {
      cout << resmic << endl;
    }
  }

  return 0;
}