#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    str a;
    cin >> a;

    for (i64 i = 'a'; i <= 'h'; i++) {
      if (i != a[0]) {
        cout << char(i) << a[1] - '0' << endl;
      }
    }
    for (i64 i = 1; i <= 8; i++) {
      if (i != a[1] - '0') {
        cout << a[0] << i << endl;
      }
    }
  }

  return 0;
}
