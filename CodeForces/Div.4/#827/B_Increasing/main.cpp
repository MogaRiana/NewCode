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

  i64 t;
  cin >> t;
  while (t--) {
    i64 n;
    set<i64> a;
    cin >> n;

    for (i64 i = 0; i < n; i++) {
      i64 x;
      cin >> x;
      a.insert(x);
    }

    if (a.size() == n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}