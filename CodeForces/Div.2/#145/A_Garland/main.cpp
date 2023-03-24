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

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    set<i64> a;
    for (i64 i = 0; i < 4; i++) {
      a.insert(s[i] - '0');
    }

    if (a.size() == 4) {
      cout << 4 << endl;
      continue;
    } else if (a.size() == 1) {
      cout << -1 << endl;
      continue;
    } else {
    }
  }

  return 0;
}