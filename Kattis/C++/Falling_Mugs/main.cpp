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

i64 c(i64 x, i64 y) { return x * x - y * y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  for (i64 i = 1; i <= 200000; i++) {
    i64 hi = i, lo = 0;

    while (hi - lo > 1) {
      i64 mid = (hi + lo) / 2;
      if (c(i, mid) < n) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }

    if (c(i, lo) == n) {
      cout << lo << " " << i << endl;
      return 0;
    }
  }

  cout << "impossible" << endl;

  return 0;
}