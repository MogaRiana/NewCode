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

i64 f[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;

  vi64 v(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> v[i];
  }

  i64 ans = 0;
  i64 d = 0, j = 1;
  for (i64 i = 1; i <= n; i++) {
    while (j <= n && d < k) {
      if (f[v[j]] == 0) {
        d++;
      }
      f[v[j]]++;

      j++;
    }

    if (d == k) {
      ans += n - (j - 1) + 1;
    }

    f[v[i]]--;
    if (f[v[i]] == 0) {
      d--;
    }
  }

  cout << ans << endl;

  return 0;
}