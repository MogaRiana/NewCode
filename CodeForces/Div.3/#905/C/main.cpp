#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 find(i64 val, i64 k) {
  i64 r = (val + k) % k;
  if (r == 0) {
    return val;
  }

  return val + k - r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, k;
    cin >> n >> k;

    i64 res = 1e9;
    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;

      res = min(res, find(x, k) - x);
    }

    cout << res << endl;
  }

  return 0;
}