#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    i64 n;
    cin >> n;
    if (n % 400 != 0) {
      cout << n / 400 + 1 << endl;
    } else {
      cout << n / 400 << endl;
    }
  }
  return 0;
}