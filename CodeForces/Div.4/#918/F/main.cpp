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

    vp64 l(n), r(n);
    for (i64 i = 0; i < n; i++) {
      cin >> r[i].first >> r[i].second;
    }

    sort(r.begin(), r.end(), [](pair<i64, i64> a, pair<i64, i64> b) {
      if (a.second < b.second) {
        return true;
      }
      if (a.second > b.second) {
        return false;
      }
      return a.first < b.first;
    });

    for (i64 i = 0; i < n; i++) {
      r[i].second = i;
    }

    l = r;

    sort(l.begin(), l.end());
  }

  return 0;
}
