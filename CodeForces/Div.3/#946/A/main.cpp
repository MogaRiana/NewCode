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
    i64 x, y;
    cin >> y >> x;

    if (x == 0) {
      if (y > 15) {
        if (y % 15 == 0) {
          cout << y / 15 << endl;
        } else {
          cout << y / 15 + 1 << endl;
        }
      } else if (y == 0) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    } else if (x == 1) {
      if (y > 11) {
        if (y % 11 == 0) {
          cout << y / 11 << endl;
        } else {
          cout << y / 11 + 1 << endl;
        }
      } else {
        cout << 1 << endl;
      }
    } else if (x == 2) {
      if (y > 7) {
        if (y % 7 == 0) {
          cout << y / 7 << endl;
        } else {
          cout << y / 7 + 1 << endl;
        }
      } else {
        cout << 1 << endl;
      }
    } else {
      if (x % 2 == 0) {
        cout << x / 2 << endl;
      } else {
        cout << x / 2 + 1 << endl;
      }
    }
  }

  return 0;
}