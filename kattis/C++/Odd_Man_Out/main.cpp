#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 t, a = 1;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;
    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (i64 i = 0; i < n; i++) {
      if (i == 0) {
        if (v[i] != v[i + 1]) {
          cout << "Case #" << a << ": " << v[i] << endl;
        }
      } else if (i == n) {
        if (v[i] != v[i - 1]) {
          cout << "Case #" << a << ": " << v[i] << endl;
        }
      } else {
        if (v[i] != v[i - 1] && v[i] != v[i + 1]) {
          cout << "Case #" << a << ": " << v[i] << endl;
        }
      }
    }

    a++;
  }

  return 0;
}