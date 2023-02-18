#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 n, a = 0, b = 0;
  cin >> n;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.rbegin(), v.rend());

  for (i64 i = 0; i < n; i++) {
    if (i % 2 == 0) {
      a += v[i];
    } else {
      b += v[i];
    }
  }

  cout << a << " " << b << endl;

  return 0;
}