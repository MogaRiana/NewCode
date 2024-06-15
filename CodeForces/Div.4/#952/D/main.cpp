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

struct p {
  i64 m = -1;
  i64 bef = 0;
  i64 ii = 0;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {

    i64 l, c;
    cin >> l >> c;

    vv v(l, vi64(c));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        char c;
        cin >> c;

        if (c == '.') {
          v[i][j] = 0;
        } else {
          v[i][j] = 1;
        }
      }
    }

    p r;
    for (i64 i = 0; i < l; i++) {
      i64 s = 0;
      bool ok = false;
      i64 bef = 0;

      for (i64 j = 0; j < c; j++) {
        if (!ok and v[i][j] == 0) {
          bef++;
        }

        if (v[i][j] == 1) {
          s++;
          ok = true;
        }
      }

      if (s > r.m) {
        r.m = s;
        r.ii = i;
        r.bef = bef;
      }
    }

    i64 i = r.ii + 1;
    i64 j = r.m / 2 + 1 + r.bef;

    cout << i << " " << j << endl;
  }

  return 0;
}