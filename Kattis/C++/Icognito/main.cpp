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
  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    map<str, i64> m;
    str s1, s2;
    for (i64 i = 0; i < n; i++) {
      cin >> s1 >> s2;
      m[s2]++;
    }

    i64 res = 1;
    for (auto &x : m) {
      res *= (1 + x.second);
    }

    cout << res - 1 << endl;
  }

  return 0;
}
