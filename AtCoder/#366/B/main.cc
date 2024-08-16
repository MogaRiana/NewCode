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

  i64 n;
  cin >> n;

  i64 m = -1;
  vec<str> v(n);
  for (auto &s : v) {
    cin >> s;
    m = max(m, (i64)s.size());
  }

  vec<vec<char>> res(n, vec<char>(m));
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < m; j++) {
      if (j >= sz(v[i])) {
        res[i][j] = '*';
      } else {
        res[i][j] = v[i][j];
      }
    }
  }

  vec<str> ans;
  for (i64 i = 0; i < m; i++) {
    bool ok = false;
    str s;
    for (i64 j = 0; j < n; j++) {
      if (res[j][i] == '*' and ok) {
        s += res[j][i];
      } else if (res[j][i] != '*') {
        s += res[j][i];
        ok = true;
      }
    }

    rvs(s);
    ans.push_back(s);
  }

  for (auto &s : ans) {
    cout << s << endl;
  }

  return 0;
}