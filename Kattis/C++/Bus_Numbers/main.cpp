#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
  i64 n;
  cin >> n;
  vi64 v(1001, 0);

  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    v[x] = 1;
  }

  i64 start = -1, endd = -1;

  for (i64 i = 1; i <= 1000; i++) {
    if (v[i] == 1) {
      if (start == -1) {
        start = i;
      }
      endd = i;
    } else {
      if (start != -1) {
        if (start == endd) {
          cout << start << " ";
        } else if (endd - start == 1) {
          cout << start << " " << endd << " ";
        } else {
          cout << start << "-" << endd << " ";
        }
        start = -1;
        endd = -1;
      }
    }
  }

  if (start != -1) {
    if (start == endd) {
      cout << start << " ";
    } else if (endd - start == 1) {
      cout << start << " " << endd << " ";
    } else {
      cout << start << "-" << endd << " ";
    }
  }

  return 0;
}