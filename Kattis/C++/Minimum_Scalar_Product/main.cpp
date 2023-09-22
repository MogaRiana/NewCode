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

  for (i64 ii = 1; ii <= t; ii++) {
    i64 n;
    cin >> n;

    vi64 a(n);
    vi64 b(n);
    for (i64 i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i64 i = 0; i < n; i++) {
      cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    i64 res = 0;
    for (i64 i = 0; i < n; i++) {
      res += a[i] * b[i];
    }

    cout << "Case #" << ii << ": " << res << endl;
  }

  return 0;
}