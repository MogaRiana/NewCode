#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

void SoE(i64 &n) {
  vector<bool> primes(n + 1, true);

  for (i64 i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (i64 p = i * i; p <= n; p += i) {
        primes[p] = false;
      }
    }
  }

  for (i64 i = 2; i <= n; i++) {
    if (primes[i]) {
      cout << i << " ";
    }
  }
}

int main() {
  i64 n;
  cin >> n;

  SoE(n);

  return 0;
}