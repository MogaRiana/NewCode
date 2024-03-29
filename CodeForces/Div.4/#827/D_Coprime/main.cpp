#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 gcd(i64 a, i64 b) {
  if (b == 0) {
    return a;
  } else {
    gcd(b, a % b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;
    map<i64, i64> v;
    for (i64 i = 1; i <= n; i++) {
      i64 a;
      cin >> a;
      v[a] = i;
    }

    i64 sum = -1;
    for (auto &x : v) {
      for (auto &y : v) {
        if (gcd(x.first, y.first) == 1) {
          sum = max(sum, x.second + y.second);
        }
      }
    }

    cout << sum << endl;
  }

  return 0;
}