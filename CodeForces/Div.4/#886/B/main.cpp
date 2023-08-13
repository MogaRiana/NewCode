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
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 res = -1, win = 0;
    for (i64 i = 1; i <= n; i++) {
      i64 rr, qq;
      cin >> rr >> qq;

      if (qq > res and rr <= 10) {
        win = i;
        res = qq;
      }
    }

    cout << win << endl;
  }

  return 0;
}
