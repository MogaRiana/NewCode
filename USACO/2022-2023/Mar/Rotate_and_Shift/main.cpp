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

  i64 n, k, t;
  cin >> n >> k >> t;
  vi64 p(k), c(n);

  for (i64 i = 0; i < k; i++) {
    cin >> p[i];
  }
  for (i64 i = 0; i < n; i++) {
    c[i] = i;
  }

  vi64 res = c;

  while (t--) {
    for (i64 i = 0; i < k; i++) {
      if (i == k - 1) {
        res[p[0]] = c[p[i]];
      } else {
        res[p[i + 1]] = c[p[i]];
      }
    }
    c = res;

    for (i64 i = 0; i < k; i++) {
      if (p[i] == n - 1) {
        p[i] = 0;
      } else {
        p[i]++;
      }
    }
  }

  cout << c[0];
  for (i64 i = 1; i < n; i++) {
    cout << " " << c[i];
  }
  return 0;
}