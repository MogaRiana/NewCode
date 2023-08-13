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

  str a, b, c;
  cin >> a >> c >> b;

  if (c == "+") {
    if (a.size() == b.size()) {
      cout << 2;
      for (i64 i = 0; i < a.size() - 1; i++) {
        cout << 0;
      }
    } else {
      i64 p = max(a.size(), b.size()) - min(a.size(), b.size());

      cout << 1;
      for (i64 i = 1; i < max(a.size(), b.size()); i++) {
        if (i == p) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
    }
  } else {
    i64 n = a.size() + b.size() - 2;

    cout << 1;
    for (i64 i = 0; i < n; i++) {
      cout << 0;
    }
  }

  return 0;
}