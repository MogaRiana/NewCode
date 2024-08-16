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
    i64 n;
    cin >> n;

    vi64 a(n);
    for (auto &x : a) {
      cin >> x;
    }

    i64 q;
    cin >> q;

    while (q--) {
      str s;
      cin >> s;

      if (sz(s) != sz(a)) {
        cout << "NO" << endl;
        continue;
      }

      bool ok = true;
      map<char, i64> m;
      for (i64 i = 0; i < sz(s); i++) {
        if (m.count(s[i])) {
          if (m[s[i]] != a[i]) {
            cout << "NO" << endl;
            ok = false;
            break;
          }
        } else {
          m[s[i]] = a[i];
        }
      }

      if (ok) {
        cout << "YES" << endl;
      }
    }
  }

  return 0;
}