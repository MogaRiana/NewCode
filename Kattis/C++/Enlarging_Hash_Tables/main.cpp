#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

bool isPrime(int num) {
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;

  if (num % 2 == 0 || num % 3 == 0)
    return false;

  for (i64 i = 5; i * i <= num; i += 6)
    if (num % i == 0 || num % (i + 2) == 0)
      return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  while (cin >> n) {
    if (n == 0) {
      return 0;
    }

    i64 p = 2 * n + 1;

    while (!isPrime(p)) {
      p++;
    }

    cout << p;
    if (!isPrime(n)) {
      cout << " (" << n << " is not prime)" << endl;
    } else {
      cout << endl;
    }
  }

  return 0;
}