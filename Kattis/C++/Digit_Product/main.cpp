#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 n;
  cin >> n;
  i64 a = n, s = 1;
  while (n > 9) {
    if (a % 10 != 0) {
      s *= a % 10;
    }
  }
  return 0;
}
