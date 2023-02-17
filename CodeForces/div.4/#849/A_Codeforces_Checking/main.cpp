#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef long double d64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  string s = "codeforces";

  i64 n;
  cin >> n;
  while (n--) {
    char a;
    bool notfound = true;
    cin >> a;

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == a) {
        cout << "YES" << endl;
        notfound = false;
        break;
      }
    }

    if (notfound) {
      cout << "NO" << endl;
    }
  }

  return 0;
}