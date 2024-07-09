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

/*
ID: Riana Moga (rianamo1)
TASK: beads
LANG: C++
*/

i64 bk(str &s, i64 ii) {
  i64 crt = 0;

  bool w = false, ok = false;
  char c = s[ii - 1], cc = s[ii - 1];
  if (c == 'w') {
    w = true;
  }

  for (i64 i = ii - 1; i >= 0; i--) {
    if (s[i] == c or s[i] == cc) {
      crt++;
    } else if (w and !ok) {
      c = s[i];
      crt++;
      ok = true;
    } else if (!w and s[i] == 'w') {
      crt++;
    } else {
      break;
    }
  }

  return crt;
}

i64 fr(str &s, i64 ii, i64 n) {
  i64 crt = 0;

  bool w = false, ok = false;
  char c = s[ii], cc = s[ii];
  if (c == 'w') {
    w = true;
  }

  for (i64 i = ii; i < sz(s); i++) {
    if (s[i] == c or s[i] == cc) {
      crt++;
    } else if (w and !ok) {
      c = s[i];
      crt++;
      ok = true;
    } else if (!w and s[i] == 'w') {
      crt++;
    } else {
      break;
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("beads.in");
  ofstream cout("beads.out");

  i64 n;
  cin >> n;

  str s;
  cin >> s;

  s += s + s;

  i64 res = -1;
  for (i64 i = n; i < 2 * n; i++) {
    res = max(res, bk(s, i) + fr(s, i, n));
  }

  cout << min(res, n) << endl;

  return 0;
}