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

  i64 n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    i64 ss = 1;
    for (i64 i = 1; i <= n; i++) {
      if (i % 10 != 0) {
        ss *= i;
        while (ss % 10 == 0) {
          ss /= 10;
        }

        ss = ss % 10;
      }
    }

    cout << ss << endl;
  }

  return 0;
}