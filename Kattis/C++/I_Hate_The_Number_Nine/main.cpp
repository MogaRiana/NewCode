#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

const i64 MOD = 1e9 + 7;

i64 bpow(i64 n, i64 m) {
  if (m == 0) {
    return 1;
  }
  if (m == 1) {
    return n;
  }

  if (m % 2 == 0) {
    i64 res = bpow(n, m / 2);
    return res * res % MOD;
  } else {
    return n * bpow(n, m - 1) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    cout << 8 * bpow(9, n - 1) % MOD << endl;
  }

  return 0;
}