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

i64 nine(i64 n) {
  i64 ans = 1;
  for (i64 i = 0; i < n; i++) {
    ans = ans * 9 % MOD;
  }

  return ans;
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

    cout << 8 * nine(n - 1) % MOD << endl;
  }

  return 0;
}