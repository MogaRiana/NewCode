#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
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

unordered_map<i64, i64> dp;
i64 MOD = 1e9 + 7;

i64 mod(i64 n) { return (n < MOD) ? n : n % MOD; }
i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

i64 bpow(i64 n, i64 p) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return mod(n);
  }

  if (p % 2 == 0) {
    i64 ans = bpow(n, p / 2);
    return mult(ans, ans);
  } else {
    return mult(bpow(n, p - 1), mod(n));
  }
}

i64 fact(i64 n) {
  if (n == 0 or n == 1) {
    return 1;
  }

  if (dp.count(n)) {
    return dp[n];
  } else {
    return dp[n] = mult(fact(n - 1), mod(n));
  }
}

i64 ifact(i64 n) { return bpow(fact(n), MOD - 2); }

i64 comb(i64 n, i64 k) {
  if (n < k) {
    return 0;
  }
  if (k == 0 or n == k) {
    return 1;
  }
  if (k == 1) {
    return mod(n);
  }

  return mult(mult(fact(n), ifact(n - k)), ifact(k));
}

i64 perm(i64 n) { return fact(n); }
i64 arn(i64 n, i64 k) { return mult(fact(n), ifact(n - k)); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << comb(5, 3) << endl;
  cout << arn(5, 3) << endl;
  cout << perm(5) << endl;

  return 0;
}