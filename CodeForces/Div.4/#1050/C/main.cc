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

  int t;
  cin >> t;

  while (t--) {
    i64 n, m;
    cin >> n >> m;

    vi64 v(m + 1, -1);
    for (i64 i = 0; i < n; i++) {
      i64 a, b;
      cin >> a >> b;
      v[a] = b;
    }

    i64 p = 1, r = m;
    if (v[1] == 0) {
      r--;
    } else {
      v[1] = p;
      p = 0;
    }

    for (i64 i = 2; i <= m; i++) {
      if (v[i] == -1) {
        v[i] = p;
        if (p == 1) {
          p = 0;
        } else {
          p = 1;
        }
      } else if (v[i] == v[i - 1]) {
        r--;
      }
    }
    cout << r << endl;
  }

  return 0;
}