#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 find(i64 n, i64 k) {
  i64 lg = log(n) / log(k);

  i64 a = pow(k, lg);
  i64 b = pow(k, lg + 1);

  if (abs(n - a) <= abs(n - b)) {
    return a;
  } else {
    return b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin{"abx.in"};
  ofstream cout{"abx.out"};

  i64 tc, m;
  map<i64, i64> res;
  cin >> tc >> m;

  while (tc--) {
    i64 nr;
    cin >> nr;

    if (res[nr] == 0) {
      res[nr] = 1e9;
      for (i64 i = 2; i <= nr / 2; i++) {
        if (abs(find(nr, i) - nr) <= abs(res[nr] - nr)) {
          res[nr] = find(nr, i);
        }
      }
    }

    cout << res[nr] << endl;
  }

  return 0;
}