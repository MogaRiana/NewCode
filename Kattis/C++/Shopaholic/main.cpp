#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  i64 res = 0, k = n % 3;
  for (i64 i = k; i < n; i += 3) {
    res += v[i];
  }

  cout << res << endl;

  return 0;
}