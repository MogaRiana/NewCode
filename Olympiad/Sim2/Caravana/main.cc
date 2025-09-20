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

  int n;
  cin >> n;

  vec<i64> a(n);
  set<i64> s1, s2;
  vi64 pr(n, 0), sf(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s2.insert(a[i]);
  }

  pr[0] = a[0];
  for (int i = 1; i < n; i++) {
    pr[i] = pr[i - 1] + a[i];
  }

  sf[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sf[i] = sf[i + 1] + a[i];
  }

  for (int i = 0; i < n - 1; i++) {
    if (pr[i] - sf[i + 1] < 0) {
      i64 aa = -(pr[i] - sf[i + 1]) / 2;
      if (s2.count(aa)) {
        cout << "YES" << endl;
        return 0;
      }
    } else if (sf[i + 1] - pr[i] < 0) {
      i64 aa = -(sf[i + 1] - pr[i]) / 2;
      if (s1.count(aa)) {
        cout << "YES" << endl;
        return 0;
      }
    }
    s1.insert(a[i]);
    s2.erase(a[i]);
  }

  cout << "NO" << endl;

  return 0;
}