#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  vi64 v = {1, 1, 1, 1, 2, 4, 4, 5, 6, 10, 10, 10, 20, 20};
  sort(v.begin(), v.end());
  i64 x;

  while (cin >> x) {
    i64 a = -1, l = 0, r = v.size() - 1;

    while (l <= r) {
      i64 m = l + (r - l) / 2;

      if (v[m] >= x) {
        a = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    if (a != -1) {
      cout << "first apparition of " << x << " is at pos: " << a << endl;
    } 
  }
}