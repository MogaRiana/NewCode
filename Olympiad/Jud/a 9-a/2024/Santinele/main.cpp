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

  ifstream cin("santinele.in");
  ofstream cout("santinele.out");

  i64 c, n, k;
  cin >> c >> n >> k;

  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  if (c == 1) {
    i64 pos = 0;
    for (i64 i = 1; i < k + 1 and i < n; i++) {
      if (v[i] >= v[pos]) {
        pos = i;
      }
    }

    i64 sol = pos;
    i64 i = pos;
    while (i < pos + k + 1 and i < n and v[i] <= v[sol]) {
      i++;
    }

    cout << i << endl;
  } else {
    i64 l = 0, res = 0;

    while (l < n) {
      i64 r = min(l + k, n);

      i64 pos = l;
      for (i64 i = l; i <= r; i++) {
        if (v[i] >= v[pos]) {
          pos = i;
        }
      }

      i64 sol = pos;
      i64 i = pos;
      while (i < pos + k + 1 and i < n and v[i] <= v[sol]) {
        i++;
      }

      res++;
      l = i;
    }

    cout << res << endl;
  }

  return 0;
}