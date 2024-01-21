#include <algorithm>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, t;
  cin >> n >> t;

  i64 sum = 0, crt = 0;
  bool ok = true;
  while (n--) {
    i64 x;
    cin >> x;

    if (ok and sum + x <= t) {
      sum += x;
      crt++;
    } else if (sum + x > t) {
      ok = false;
    }
  }

  cout << crt << endl;

  return 0;
}