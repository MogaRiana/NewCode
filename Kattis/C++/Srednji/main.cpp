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
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;

  vector<i64> v(n);

  i64 ss;
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];

    if (v[i] == k) {
      ss = i;
    }
  }

  map<i64, i64> m;
  m[0] = 1;

  i64 sum = 0;

  for (i64 i = ss + 1; i < n; i++) {
    if (v[i] > k) {
      sum++;
    } else {
      sum--;
    }

    m[sum]++;
  }

  i64 ans = m[0];
  sum = 0;

  for (i64 i = ss - 1; i >= 0; i--) {
    if (v[i] > k) {
      sum++;
    } else {
      sum--;
    }

    ans += m[-sum];
  }

  cout << ans << endl;

  return 0;
}