#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 n, x = 0, k = 0, l = 1;
  str s;
  bool ok = true;
  cin >> n >> s;

  for (i64 i = 0; i < s.size() - x; i += x + 1) {
    i64 a = s[i] - 48;

    if (k == 9 && ok) {
      x++;
      k = 0;
      ok = false;
    }
    if (k == 89) {
      x++;
    }

    if (x == 1) {
      i64 b = s[i + 1] - 48;
      a = (a * 10) + b;
    } else if (x == 2) {
      a = 100;
    }

    k++;

    if (a != l) {
      cout << l << endl;
      return 0;
    }

    l++;
  }

  return 0;
}