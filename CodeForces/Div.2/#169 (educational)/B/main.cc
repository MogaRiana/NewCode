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
    i64 a, b, x, y;
    cin >> a >> b >> x >> y;

    if (x == b) {
      cout << 2 << endl;
      continue;
    }

    if (a == x and b == y) {
      cout << y - x << endl;
      continue;
    }

    if (a == x) {
      cout << min(b, y) - a + 1 << endl;
      continue;
    }

    if (b == y) {
      cout << b - max(a, x) + 1 << endl;
      continue;
    }

    if (x > b) {
      cout << x - b << endl;
      continue;
    }

    if (x < b) {
      if (x > a) {
        cout << min(b, y) - x + 2 << endl;
      }
      if (x < a) {
        if (y < a) {
          cout << a - y << endl;
        }

        if (a == y) {
          cout << 2 << endl;
        }

        if (a < y) {
          cout << min(b, y) - a + 2 << endl;
        }
      }
    }
  }

  return 0;
}