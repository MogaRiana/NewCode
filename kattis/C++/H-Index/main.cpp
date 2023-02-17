#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

int main() {
  i64 n, h = 0;
  cin >> n;
  vi64 v(n);

  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.rbegin(), v.rend());

  for (i64 i = 0; i < n; i++) {
    if (v[i] >= i + 1) {
      h = i + 1;
    } else {
      break;
    }
  }

  cout << h << endl;

  return 0;
}