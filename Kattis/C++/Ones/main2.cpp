#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
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

  i64 n;
  while (cin >> n) {
    i64 res = 1;
    i64 d = 1;

    while (d % n != 0) {
      d *= 10;
      d += 1;
      d = d % n;
      ++res;
    }

    cout << res << endl;
  }

  return 0;
}