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
    str s, ss = "codeforces";
    cin >> s;

    i64 crt = 0;
    for (i64 i = 0; i < 10; i++) {
      if (s[i] != ss[i]) {
        crt++;
      }
    }

    cout << crt << endl;
  }

  return 0;
}