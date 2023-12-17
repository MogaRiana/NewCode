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

i64 fact[100001];
i64 const M = 1e9 + 7;

void do_fact(i64 n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % M;
  }
}

i64 bexp(i64 b, i64 e) {
  if (e == 0) {
    return 1;
  }
  if (e % 2 == 0) {
    i64 ans = bexp(b, e / 2);
    return (ans * ans) % M;
  }
  i64 ans = bexp(b, e - 1);
  return (ans * (b % M)) % M;
}

i64 cmb(i64 a, i64 b) {
  return fact[a] * bexp(fact[b] * fact[a - b] % M, M - 2) % M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  if (n <= 1) {
    cout << 0 << endl;
  } else if (n == 2) {
    cout << 1 << endl;
  } else {
    i64 sum = 1;
    do_fact(n);
    for (i64 i = 1; i < n - 1; i++) {
      sum += cmb(n, i) % M;
    }
    cout << sum;
  }

  return 0;
}
