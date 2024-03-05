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

i64 MOD = 1e9 + 7;
unordered_map<i64, i64> dp;

i64 mod(i64 n) { return n < MOD ? n : n % MOD; }

i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

i64 fact(i64 n) {
  if (n == 0 or n == 1)
    return 1;

  if (dp.count(n)) {
    return dp[n];
  }

  return dp[n] = mod(mod(n) * fact(n - 1));
}

i64 bpow(i64 a, i64 b) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return mod(a);
  }

  if (b % 2 == 0) {
    i64 ans = bpow(a, b / 2);
    return mult(ans, ans);
  } else {
    return mult(bpow(a, b - 1), mod(a));
  }
}

i64 ifact(i64 n) {
  i64 x = fact(n);
  return bpow(x, MOD - 2);
}

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 tot = 0;
    for (i64 i = 0; i <= n; i++) {
      if ((i * 5 + (n - i)) % 3 == 0) {
        tot += comb(n, i) % MOD;
      }
    }

    cout << tot % MOD << endl;
  }

  return 0;
}