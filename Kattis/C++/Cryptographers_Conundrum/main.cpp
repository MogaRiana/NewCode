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

  str s;
  cin >> s;

  i64 crt = 0;
  for (i64 i = 0; i < s.size(); i++) {
    if ((i + 1) % 3 == 0) {
      if (s[i] != 'R') {
        crt++;
      }
    } else if ((i + 1) % 3 == 1) {
      if (s[i] != 'P') {
        crt++;
      }
    } else if ((i + 1) % 3 == 2) {
      if (s[i] != 'E') {
        crt++;
      }
    }
  }

  cout << crt << endl;

  return 0;
}