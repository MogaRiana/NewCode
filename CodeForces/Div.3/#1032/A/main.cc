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
    i64 n, pos;
    cin >> n >> pos;

    if (n == 1) {
      int k;
      cin >> k;

      cout << abs(pos - k) << endl;
      continue;
    }

    i64 v[n];
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    i64 l = v[0], r = v[n - 1];

    if (pos < l) {
      cout << r - pos << endl;
    } else if (pos >= l and pos <= r) {
      cout << r - l + min(r - pos, pos - l) << endl;
    } else {
      cout << pos - l << endl;
    }
  }

  return 0;
}