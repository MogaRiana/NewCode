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

const i64 MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  map<i64, i64> m;
  for (int i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    m[x]++;
  }

  i64 res = 1;
  for (auto &x : m) {
    res *= (x.sd + 1);
    res %= MOD;
  }

  cout << res - 1 << endl;

  return 0;
}