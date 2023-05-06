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
    i64 n;
    cin >> n;

    vi64 v(n);
    i64 crt = 0;
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == n) {
        crt++;
      }
    }

    for (i64 i = 0; i < n; i++) {
      if (v[i] > crt && v[i] != n) {
        crt++;
      }
    }

    if (crt == n) {
      cout << -1 << endl;
    } else {
      cout << crt << endl;
    }
  }

  return 0;
}