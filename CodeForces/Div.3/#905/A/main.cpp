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

    i64 crt = 0;
    char cur = '1';
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == cur) {
        crt++;
      } else {
        if (s[i] != '0' and cur != '0') {
          crt += abs(cur - s[i]) + 1;
        } else if (cur != '0') {
          crt += abs(cur - '0' - 10) + 1;
        } else {
          crt += abs(10 - (s[i] - '0')) + 1;
        }
        cur = s[i];
      }
    }

    cout << crt << endl;
  }

  return 0;
}