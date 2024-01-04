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

  i64 t;
  cin >> t;

  while (t--) {
    i64 a, b, c;
    cin >> a >> b >> c;

    if (a == b) {
      cout << c << endl;
    } else if (a == c) {
      cout << b << endl;
    } else if (b == c) {
      cout << a << endl;
    }
  }

  return 0;
}
