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

  i64 pos = 1;
  str s;
  cin >> s;

  for (i64 i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (pos == 1) {
        pos = 2;
      } else if (pos == 2) {
        pos = 1;
      }
    } else if (s[i] == 'B') {
      if (pos == 2) {
        pos = 3;
      } else if (pos == 3) {
        pos = 2;
      }
    } else if (s[i] == 'C') {
      if (pos == 3) {
        pos = 1;
      } else if (pos == 1) {
        pos = 3;
      }
    }
  }

  cout << pos << endl;

  return 0;
}