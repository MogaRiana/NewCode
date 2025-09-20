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

bool ver(i64 n) {
  while (n > 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    i64 a, b;
    cin >> a >> b;

    if (b % 2 == 0) {
      if (a % 2 == 1) {
        if (!ver(b)) {
          cout << -1 << endl;
          continue;
        } else {
          int x = b / 2;
          cout << a * x + b / x << endl;
          continue;
        }
      }
      if (a % 2 == 0) {
        int x = b / 2;
        cout << a * x + b / x << endl;
        continue;
      }
    } else {
      if (a % 2 == 0) {
        cout << -1 << endl;
        continue;
      } else {
        cout << a * b + 1 << endl;
        continue;
      }
    }
  }

  return 0;
}