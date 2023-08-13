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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    i64 n;
    cin >> n >> s;

    char a = s[0];
    bool ok = false;
    for (i64 i = 1; i < n; i++) {
      if (ok) {
        a = s[i];
        ok = false;
        continue;
      }
      if (s[i] == a) {
        cout << a;
        ok = true;
      }
    }

    cout << endl;
  }

  return 0;
}