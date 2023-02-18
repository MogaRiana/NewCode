#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n;
  cin >> n;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.rbegin(), v.rend());

  i64 sum = 0;
  for (i64 i = 0; i < n; i++) {
    if ((i + 1) % 3 != 0) {
      sum += v[i];
    }
  }

  cout << sum << endl;

  return 0;
}