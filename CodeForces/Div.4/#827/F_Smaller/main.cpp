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

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 sums = 1, sumt = 1;
    i64 op;
    cin >> op;
    str s = "a", t = "a";
    char maxs = 'a', maxt = 'a';

    while (op--) {
      i64 c, k;
      str x;
      cin >> c >> k >> x;

      sort(x.begin(), x.end());
      if (c == 1) {
        sums += x.size() * k;
        maxs = x[x.size() - 1];
      } else {
        sumt += x.size() * k;
        maxt = x[x.size() - 1];
      }

      if (maxs < maxt) {
        cout << "YES" << endl;
      } else if (maxs == maxt && sums < sumt) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}