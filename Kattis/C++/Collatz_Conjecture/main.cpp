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

void collatz(i64 n, i64 steps, map<i64, i64> &m) {
  m[steps] = n;

  if (n == 1) {
    return;
  }

  if (n % 2 == 1) {
    collatz(n * 3 + 1, ++steps, m);
  } else {
    collatz(n / 2, ++steps, m);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 a, b;

  while (cin >> a >> b) {
    if (!a and !b) {
      return 0;
    }

    map<i64, i64> x, y;

    i64 steps = 0;
    collatz(a, steps, x);

    steps = 0;
    collatz(b, steps, y);

    i64 ans1 = 0, ans2 = 0;
    i64 sol = 0;

    for (auto &c : x) {
      bool ok = true;
      for (auto &cc : y) {
        if (c.sd == cc.sd) {
          ans1 = c.ft;
          ans2 = cc.ft;
          sol = c.sd;
          ok = false;
        }
      }
      if (!ok) {
        break;
      }
    }

    cout << a << " needs " << ans1 << " steps, " << b << " needs " << ans2
         << " steps, they meet at " << sol << endl;
  }

  return 0;
}