#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n, t;
  cin >> n >> t;
  if (t == 1) {
    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << 7 << endl;
  }
  if (t == 2) {
    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }
    if (v[0] > v[1]) {
      cout << "Bigger" << endl;
    } else if (v[0] == v[1]) {
      cout << "Equal" << endl;
    } else {
      cout << "Smaller" << endl;
    }
  }
  if (t == 3) {
    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.begin() + 3);
    cout << v[1] << endl;
  }
  if (t == 4) {
    i64 sum = 0, a;
    for (i64 i = 0; i < n; i++) {
      cin >> a;
      sum += a;
    }
    cout << sum << endl;
  }
  if (t == 5) {
    i64 sum = 0, a;
    for (i64 i = 0; i < n; i++) {
      cin >> a;
      if (a % 2 == 0) {
        sum += a;
      }
    }
    cout << sum << endl;
  }
  if (t == 6) {
    vector<char> v;
    i64 a;
    for (i64 i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a % 26 + 97);
    }
    for (i64 i = 0; i < n; i++) {
      cout << v[i];
    }
  }
  if (t == 7) {
    vi64 v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }
    i64 i = 0, crt = 1;
    while (crt <= 100000) {
      i = v[i];
      if (i > n - 1 || i < 0) {
        cout << "Out" << endl;
        return 0;
      }
      if (i == n - 1) {
        cout << "Done" << endl;
        return 0;
      }
      crt++;
    }
    cout << "Cyclic" << endl;
  }
  return 0;
}
