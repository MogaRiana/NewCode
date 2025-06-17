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

void tr(str &s, vi64 &v, i64 pos) {
  reverse(s.begin(), s.end());
  for (int j = 0; j < s.size(); j++) {
    v[pos] += (s[j] == '1') * (1 << j);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;
  vi64 v(n, 0);

  for (i64 i = 0; i < n; i++) {
    str s;
    cin >> s;
    tr(s, v, i);
  }

  i64 res = 32;
  for (i64 i = 0; i < n; i++) {
    for (i64 j = i + 1; j < n; j++) {
      res = min(res, (i64)__builtin_popcount(v[i] ^ v[j]));
    }
  }

  cout << res << endl;

  return 0;
}