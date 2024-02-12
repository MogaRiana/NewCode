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

  i64 n, q;
  cin >> n >> q;

  vi64 v(n);
  for (auto &i : v) {
    cin >> i;
  }

  while (q--) {
    i64 c, a, b;
    cin >> c >> a >> b;

    a--;
    if (c == 1) {
      v[a] = b;
    } else {
      b--;
      cout << abs(v[a] - v[b]) << endl;
    }
  }

  return 0;
}