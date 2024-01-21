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

  i64 n, a = 0;
  while (cin >> n) {
    if (!n) {
      break;
    }

    vector<str> v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];
    }

    cout << "SET " << ++a << endl;
    for (i64 i = 0; i < n; i += 2) {
      cout << v[i] << endl;
    }
    for (i64 i = (n % 2 == 0) ? n - 1 : n - 2; i > 0; i -= 2) {
      cout << v[i] << endl;
    }
  }

  return 0;
}