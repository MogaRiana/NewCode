#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<i32> vi32;
typedef vector<vi64> vv;
typedef vector<vector<i32>> vv32;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    double a, b, c;
    cin >> a >> b >> c;

    double d = (a + b) / 2;
    double res = max(a, b) - d;
    res /= c;
    int p = int(res);

    if (res != p) {
      res++;
    }

    res = int(res);

    cout << res << endl;
  }

  return 0;
}