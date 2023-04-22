#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 subarray(i64 crt, i64 i, vi64 &v) {
  bool ok = true;

  for (i64 j = i; j < v.size(); j++) {
    if (v[j] != v[i]) {
      if (v[j] > v[i]) {
        crt++;
      }

      ok = false;
      i = j;
      break;
    }
  }

  if (ok) {
    crt++;
  }

  return crt;
}

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
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }

    i64 crt = 0;
    for (i64 i = 0; i < n; i++) {
      if (i != 0) {
        if (v[i - 1] > v[i]) {
          crt = subarray(crt, i, v);
        }
      } else if (i == 0) {
        if (v[i + 1] > v[i]) {
          crt++;
        } else if (v[i + 1] == v[i]) {
          crt = subarray(crt, i, v);
        }
      }
    }

    if (crt > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}