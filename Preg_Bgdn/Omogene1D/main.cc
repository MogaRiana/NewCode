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

  i64 n;
  cin >> n;

  i64 c0 = 0, c1 = 0, c2 = 0;
  i64 res = 0;

  map<p64, i64> m;
  m[{0, 0}] = 1;

  for (i64 i = 0; i < n; i++) {
    i64 a;
    cin >> a;

    if (a == 0) {
      c0++;
    } else if (a == 1) {
      c1++;
    } else {
      c2++;
    }

    i64 d1 = c0 - c1;
    i64 d2 = c0 - c2;

    if (m.count({d1, d2})) {
      res += m[{d1, d2}];
    }

    m[{d1, d2}]++;
  }

  cout << res << endl;

  return 0;
}