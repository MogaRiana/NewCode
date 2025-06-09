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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, x;
  cin >> n >> x;

  vi64 v(n);
  for (auto &i : v) {
    cin >> i;
  }

  srt(v);
  i64 sum = 0;
  map<i64, i64> f;
  for (int i = 0; i < (1 << (n / 2 - 1)); i++) {
    sum = 0;
    for (int j = 0; j < n / 2 - 1; j++) {
      if (i & (1 << j)) {
        sum += v[j];
      }
    }
    f[sum]++;
  }

  i64 res = 0;
  for (int i = 0; i < (1 << ((n + 1) / 2 + 1)); i++) {
    sum = 0;
    for (int j = 0; j < (n + 1) / 2 + 1; j++) {
      if (i & (1 << j)) {
        sum += v[n / 2 - 1 + j];
      }
    }
    if (f.find(x - sum) != f.end()) {
      res += f[x - sum];
    }
  }

  return 0;
}