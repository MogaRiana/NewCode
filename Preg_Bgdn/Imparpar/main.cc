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

unordered_map<i64, i64> dp;
i64 MOD = 1e9 + 7;

i64 mod(i64 n) { return (n < MOD) ? n : n % MOD; }
i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  i64 ans = fact(n / 2);
  cout << ans * ans << endl;

  return 0;
}