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
    i64 n;
    str s;
    cin >> n >> s;

    map<char, i64> m;
    bool ok = true;
    for (i64 i = 1; i <= n; i++) {
      if (m[s[i - 1]] == 0) {
        m[s[i - 1]] = i;
      } else {
        if (i % 2 != m[s[i - 1]] % 2) {
          cout << "NO" << endl;
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      cout << "YES" << endl;
    }
  }

  return 0;
}