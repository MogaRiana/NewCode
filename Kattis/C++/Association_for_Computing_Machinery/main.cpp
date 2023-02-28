#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
#define endl '\n'

int main() {
  i64 n, k;
  cin >> n >> k;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  i64 crt = 0, tot = 0, p = 0;
  swap(v[0], v[k]);
  sort(++v.begin(), v.end());

  for (i64 i = 0; i < n; i++) {
    if (v[i] + tot <= 300) {
      crt++;
      tot += v[i];
      p += tot;
    } else {
      break;
    }
  }

  cout << crt << " " << p << endl;

  return 0;
}