#include <bits/stdc++.h>

using namespace std;

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

  i64 n, t, k;
  cin >> n >> t >> k;

  i64 l = 1, r = n;
  i64 lf = k;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    cout << "? " << l << " " << mid << endl;
    i64 ones;
    cin >> ones;

    i64 z = mid - l + 1 - ones;
    if (z == 1 and l == r) {
      cout << "! " << l << endl;
      return 0;
    }

    if (z < lf) {
      l = mid + 1;
      lf -= z;
    } else {
      r = mid;
    }
  }

  return 0;
}