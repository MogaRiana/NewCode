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

  i64 n;
  cin >> n;

  map<set<i64>, i64> m;
  for (i64 i = 0; i < n; i++) {
    set<i64> a;
    for (i64 j = 0; j < 5; j++) {
      i64 x;
      cin >> x;
      a.insert(x);
    }
    m[a]++;
  }

  i64 ans = 0;
  for (auto &x : m) {
    ans = max(ans, x.second);
  }

  i64 res = 0;
  for (auto &x : m) {
    if (x.second == ans) {
      res += x.second;
    }
  }

  cout << res << endl;

  return 0;
}