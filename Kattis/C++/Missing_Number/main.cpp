#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 n, len = 1, i = 0, c, l = 1;
  string s;
  bool ok = true, found = false;
  cin >> n >> s;

  while (i < s.size()) {
    if (len == 1) {
      c = s[i++] - '0';
      if (c == 9) {
        len = 2;
      }
    } else if (len == 2) {
      c = (s[i++] - '0') * 10;
      c += s[i++] - '0';
      if (c == 99) {
        len == 3;
      }
    } else {
      c = (s[i++] - '0') * 100;
      c += (s[i++] - '0') * 10;
      c += s[i++] - '0';
    }
    if (c != l) {
      cout << l << endl;
      found = true;
      break;
    }
    l++;
  }

  if (!found) {
    cout << l << endl;
  }

  return 0;
}