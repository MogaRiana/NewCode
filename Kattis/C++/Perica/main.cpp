#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 n, k;
i64 fact[100001];
i64 const M = 1e9 + 7;

void do_fact() {
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  do_fact();
  i64 res = 0;

  for (i64 i = k - 1; i < n; i++) {
    res += cmb(i, k - 1) * v[i] % M;
    res %= M;
  }
  cout << res << endl;
  return 0;
}