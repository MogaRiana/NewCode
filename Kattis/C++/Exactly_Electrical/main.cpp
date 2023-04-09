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

  i64 a, b, c, d, t;
  cin >> a >> b >> c >> d >> t;

  i64 res = abs(a - c) + abs(b - d);
  if (res > t) {
    cout << "N" << endl;
  } else if (res == t) {
    cout << "Y" << endl;
  } else {
    i64 dist = abs(a - c) + abs(b - d - 1);

    if ((t - dist) % 2 == 1) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }

  return 0;
}