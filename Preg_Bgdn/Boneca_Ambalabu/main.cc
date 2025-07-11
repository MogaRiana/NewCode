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

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vi64 v(n);
    vi64 cnt(30, 0);

    for (auto &i : v) {
      cin >> i;
      for (int bit = 0; bit < 30; bit++) {
        cnt[bit] += ((i >> bit) & 1);
      }
    }

    i64 res = 0;
    for (auto &i : v) {
      i64 sum = 0;
      for (int bit = 0; bit < 30; bit++) {
        if ((i >> bit) & 1) {
          sum += (1 << bit) * (n - cnt[bit]);
        } else {
          sum += (1 << bit) * cnt[bit];
        }
      }
      res = max(res, sum);
    }

    cout << res << endl;
  }

  return 0;
}