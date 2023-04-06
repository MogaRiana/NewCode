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
    i64 n, nr;
    str s;
    cin >> n >> nr >> s;

    i64 pos = -1;
    for (i64 i = 0; i < n; i++) {
      if (s[i] - '0' < nr) {
        pos = i;
        break;
      } else {
        cout << s[i];
      }
    }

    cout << nr;
    if (pos != -1) {
      for (i64 i = pos; i < n; i++) {
        cout << s[i];
      }
    }
    cout << endl;
  }

  return 0;
}