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

  i64 n, p, sum = 0, crt = 0;
  cin >> p >> n;

  for (i64 i = 0; i < n; i++) {
    str s;
    i64 a;
    cin >> s >> a;

    if (s == "enter") {
      if (sum + a <= p) {
        sum += a;
      } else {
        crt++;
      }
    } else if (s == "leave") {
      sum -= a;
    }
  }

  cout << crt << endl;

  return 0;
}