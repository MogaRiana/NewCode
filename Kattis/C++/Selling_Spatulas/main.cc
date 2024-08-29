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

struct r {
  i64 res = 0;
  i64 s = 0, e = 0;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    vp64 v(n);
    for (auto &p : v) {
      cin >> p.ft;
      double d;
      cin >> d;

      p.sd = (i64)(d * 100);
    }

    r res;
    for (i64 i = 0; i < n; i++) {
      i64 sum = -8, s = v[i].ft, t = v[i].ft, e = v[i].ft;
      i64 ans = 0;

      for (i64 j = i; j < n; j++) {
        sum += v[j].sd - 8 * (v[j].ft - t);
        t = v[j].ft;

        if (sum > res.res) {
          res.res = sum;
          res.s = s;
          res.e = v[j].ft;
        }

        if (sum < 0) {
          sum = 0;
          s = v[j].ft;
          e = v[j].ft;
        }
      }
    }

    if (res.res == 0) {
      cout << "no profit" << endl;
      continue;
    }

    cout << res.res / 100.0 << " " << res.s << " " << res.e << endl;
  }

  return 0;
}