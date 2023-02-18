#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main() {
  i64 n, a, s = 0;
  cin >> n;
  for (i64 i = 0; i < n; i++) {
    cin >> a;
    s += a;
  }
  cout << s << endl;
  return 0;
}
