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

    map<i64, i64> mm;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;
      mm[x]++;
    }

    if (mm.size() == 1 and mm.begin()->first != 0) {
      cout << "NO" << endl;
      continue;
    }

    i64 ff = mm.begin()->first;

    bool ok = true;
    for (auto x : mm) {
      if (x.first != ff) {
        if (mm[x.first - 1] < mm[x.first]) {
          ok = false;
          break;
        }
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