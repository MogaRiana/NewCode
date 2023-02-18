#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    i64 n;
    bool ok = true;
    string s1, s2;
    cin >> n >> s1 >> s2;

    for (i64 j = 0; j < n; j++) {
      if (s1[j] == 'R' && s2[j] == 'B') {
        cout << "NO" << endl;
        ok = false;
        break;
      }
      if (s1[j] == 'R' && s2[j] == 'G') {
        cout << "NO" << endl;
        ok = false;
        break;
      }
      if (s1[j] == 'G' && s2[j] == 'R') {
        cout << "NO" << endl;
        ok = false;
        break;
      }
      if (s1[j] == 'B' && s2[j] == 'R') {
        cout << "NO" << endl;
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "YES" << endl;
    }
  }
  return 0;
}