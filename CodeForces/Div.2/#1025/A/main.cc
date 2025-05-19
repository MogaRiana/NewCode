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

    vi64 v(n + 1, 0);
    vi64 a(n + 1);

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    if (a[1] == 0 and a[2] == 0) {
      cout << "YES" << endl;
      continue;
    }

    if (a[1] == 1) {
      v[1] = 2;
    }
    // else {
    //    v[2] = 1;
    //  }

    bool ok = false;
    int cnt0 = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] == 0 and a[i + 1] == 0) {
        cout << "YES" << endl;
        ok = true;
        break;
      }

      if (a[i] == 0) {
        cnt0++;
      }
    }

    if (ok) {
      continue;
    }

    if (a[n] == 0) {
      cnt0++;
    }

    if (cnt0 >= 1 and cnt0 < n) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}