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

i32 n, t, p;

i32 slv(vi32 &a) {
  i32 crt = 0, pp = 0, v = -1;
  for (auto &x : a) {
    if (x >= t) {
      pp++;
      if (pp == p) {
        return 0;
      }
    } else {
      crt++;
      if (crt + pp == p) {
        return t - x;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> t >> p;

  vi32 a(n);
  for (auto &x : a) {
    cin >> x;
  }

  rsrt(a);
  cout << slv(a) << endl;

  return 0;
}