#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  short t;
  cin >> t;
  for (short i = 0; i < t; i++) {
    short n, crt = 0;
    vector<short> v = {0, 0, 0, 0, 0};
    string s;
    cin >> n >> s;

    if (n != 5) {
      cout << "NO" << endl;
      continue;
    }

    for (short j = 0; j < n; j++) {
      if (s[j] == 'T') {
        v[0]++;
      } else if (s[j] == 'i') {
        v[1]++;
      } else if (s[j] == 'm') {
        v[2]++;
      } else if (s[j] == 'u') {
        v[3]++;
      } else if (s[j] == 'r') {
        v[4]++;
      }
    }

    bool ok = true;
    for (short j = 0; j < 5; j++) {
      if (v[j] != 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}