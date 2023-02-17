#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 e, f, c, s = 0;
  cin >> e >> f >> c;

  e += f;
  i64 num_tot = e;
  while (true) {
    if (num_tot / c == 0) {
      break;
    } else {
      s += num_tot / c;
      i64 eep = num_tot / c;
      num_tot = num_tot % c + eep;
    }
  }

  cout << s << endl;

  return 0;
}