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

  i64 n, m, c;
  cin >> n >> m >> c;

  vi64 v(n);
  for (auto &i : v) {
    cin >> i;
  }

  set<i64> res;
  for (i64 i = 0; i < n; i++) {
    i64 mn = 1e9, mx = -1e9, j;
    for (j = i; j < i + m and j < n; j++) {
      mn = min(v[j], mn);
      mx = max(v[j], mx);
      if (mx - mn > c) {
        break;
      }
    }

    if (mx - mn <= c and j == i + m) {
      res.insert(i + 1);
    }
  }

  for (auto &x : res) {
    cout << x << endl;
  }

  if (res.empty()) {
    cout << "NONE" << endl;
  }

  return 0;
}
