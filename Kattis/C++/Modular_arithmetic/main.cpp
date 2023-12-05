#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;

i64 gcd(i64 a, i64 b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

i64 phi(i64 n) {
  i64 result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

i64 m, t;

i64 bexp(i64 b, i64 e) {
  if (e == 0) {
    return 1;
  }
  if (e % 2 == 0) {
    i64 ans = bexp(b, e / 2);
    return (ans * ans) % m;
  }
  i64 ans = bexp(b, e - 1);
  return (ans * (b % m)) % m;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    cin >> m >> t;
    if (m == 0 && t == 0) {
      break;
    }

    i64 a, b;
    char c;
    while (t--) {
      cin >> a >> c >> b;
      switch (c) {
      case '+':
        cout << (a % m + b % m) % m << endl;
        break;
      case '-':
        cout << (m + a - b) % m << endl;
        break;
      case '*':
        cout << ((a % m) * (b % m)) % m << endl;
        break;
      case '/':
        if (gcd(b, m) != 1) {
          cout << -1 << endl;
        } else {
          i64 ivs = bexp(b, phi(m) - 1);
          cout << ((a % m) * ivs) % m << endl;
        }
        break;
      default:
        break;
      }
    }
  }

  return 0;
}