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
    vi64 v(n);

    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    v[0]++;

    i64 res = 1;
    for (i64 i = 0; i < n; i++) {
      res *= v[i];
    }

    cout << res << endl;
  }

  return 0;
}
