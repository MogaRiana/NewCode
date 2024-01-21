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
    i64 n;
    cin >> n;

    set<i64> a;

    vector<i64> v(n);

    for (auto &x : v) {
      cin >> x;
    }
    a.insert(0);
    i64 sum = 0;
    bool found = false;

    for (i64 i = 0; i < n; i++) {
      if (i % 2 == 1) {
        v[i] *= -1;
      } else {
        v[i] *= 1;
      }
      sum += v[i];
      if (a.count(sum)) {
        cout << "YES" << endl;
        found = true;
        break;
      }
      a.insert(sum);
    }

    if (!found) {
      cout << "NO" << endl;
    }
  }

  return 0;
}
