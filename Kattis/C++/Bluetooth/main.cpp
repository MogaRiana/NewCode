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
typedef pair<i32, i32> p64;
typedef string str;
typedef vector<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi32> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vec<pair<bool, bool>> l(9, {true, true}), r(9, {true, true});
  bool lf = true, rt = true;
  while (n--) {
    char c1, c2, mb;
    cin >> c1 >> c2 >> mb;

    i64 ind;
    if (c1 == '-' or c1 == '+') {
      ind = c2 - '0';
    } else {
      ind = c1 - '0';
    }

    if (c1 - '0' == ind) {
      if (c2 == '+') {
        if (mb == 'm') {
          r[ind].ft = false;
        } else {
          rt = false;
        }
      } else {
        if (mb == 'm') {
          r[ind].sd = false;
        } else {
          rt = false;
        }
      }
    } else {
      if (c1 == '+') {
        if (mb == 'm') {
          l[ind].ft = false;
        } else {
          lf = false;
        }
      } else {
        if (mb == 'm') {
          l[ind].sd = false;
        } else {
          lf = false;
        }
      }
    }
  }

  i64 crtrd = 0, crtld = 0, crtru = 0, crtlu = 0;
  for (i64 i = 1; i < 9; i++) {
    if (lf) {
      if (l[i].ft) {
        crtlu++;
      }
      if (l[i].sd) {
        crtld++;
      }
    }
    if (rt) {
      if (r[i].ft) {
        crtru++;
      }
      if (r[i].sd) {
        crtrd++;
      }
    }
  }

  if (rt) {
    if (crtru and crtrd) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  } else if (lf) {
    if (crtlu and crtld) {
      cout << 0 << endl;
    } else {
      cout << 2 << endl;
    }
  } else {
    cout << 2 << endl;
  }

  return 0;
}