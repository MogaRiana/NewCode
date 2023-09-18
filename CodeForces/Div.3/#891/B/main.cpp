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

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    if (s.size() == 1) {
      if (s[0] - '0' < 5) {
        cout << s << endl;
      } else {
        cout << 10 << endl;
      }

      continue;
    }

    i64 crt = 0, p, m;
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] - '0' >= 5) {
        crt++;
        p = i;
        m = p;
        break;
      }
    }

    if (crt == 0) {
      cout << s << endl;
      continue;
    }

    if (p == 0 and s[p] - '0' >= 5) {
      s[p] = '1';
      s.push_back('0');

      for (i64 i = m + 1; i < s.size(); i++) {
        s[i] = '0';
      }
    } else {
      i64 i = p - 1;
      do {
        s[i]++;
        s[p] = '0';
        p = i;
        i = p - 1;
      } while (p > 0 and s[p] - '0' >= 5);

      for (i64 i = m; i < s.size(); i++) {
        s[i] = '0';
      }

      if (p == 0 and s[p] - '0' >= 5) {
        s[p] = '1';
        s.push_back('0');
      } else if (p != 0 and s[p] - '0' >= 5) {
        s[p - 1]++;
        s[p] = '0';
      }
    }
    cout << s << endl;
  }

  return 0;
}