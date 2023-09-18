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
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;
    vi64 v(n);

    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    vi64 a;

    for (i64 i = 0; i < n; i++) {
      if (i == 0) {
        a.push_back(v[i]);
        continue;
      }

      if (v[i] < a.back()) {
        a.push_back(v[i]);
        a.push_back(v[i]);
      } else {
        a.push_back(v[i]);
      }
    }

    cout << a.size() << endl;

    for (auto &x : a) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}