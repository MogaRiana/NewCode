#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int fact[200000];
const i64 MOD = 555557;

void PreProcess() {
  fact[0] = 1;

  for (int i = 1; i <= 200000; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
  }
}

i64 bpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b & 1) {
    return a * bpow(a, b - 1) % MOD;
  }

  i64 aux = bpow(a, b >> 1);
  return aux * aux % MOD;
}

i64 ifact(i64 n) { return bpow(n, MOD - 2); }

i64 comb(i64 n, i64 k) {
  if (n < k)
    return 0;
  if (k == 0 or n == k)
    return 1;

  return (fact[n] * ifact(fact[n - k])) % MOD * ifact(fact[k]) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"necuatie.in"};
  ofstream cout{"necuatie.out"};

  PreProcess();

  i64 n;
  cin >> n;

  i64 res = 1;
  for (i64 i = 1; i <= n / 2; i++) {
    res = (res + ((comb(n, i) * comb(n - i, i)) % MOD)) % MOD;
  }

  cout << res << endl;

  return 0;
}