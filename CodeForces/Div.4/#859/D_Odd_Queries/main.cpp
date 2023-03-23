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

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, q;
    cin >> n >> q;

    vi64 v(n + 1, 0);
    cin >> v[1];
    for (i64 i = 2; i <= n; i++) {
      cin >> v[i];
      v[i] += v[i - 1];
    }

    while (q--) {
      i64 l, r, k;
      cin >> l >> r >> k;

      i64 sum = v[l - 1] + (v[n] - v[r]) + (k * (r - l + 1));
      if (sum % 2 == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}