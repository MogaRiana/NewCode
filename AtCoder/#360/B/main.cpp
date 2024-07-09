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

bool ver(str &s, str &t) {
  i64 k = 0;

  for (i64 i = 0; i < sz(s); i++) {
    if (s[i] == t[k]) {
      k++;
    }

    if (k == sz(t)) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s, t;
  cin >> s >> t;

  i64 ns = sz(s);

  if (!ver(s, t)) {
    cout << "No" << endl;
    return 0;
  }

  bool kk = false;
  i64 crt = 0, ii = -1;
  for (i64 i = 0; i < ns; i++) {
    if (s[i] == t[0] and !kk) {
      ii = i;

      if (sz(t) > 1) {
        kk = true;
      }
      continue;
    }

    if (kk) {
      crt++;
    }
    if (s[i] == t[1]) {
      break;
    }
  }

  if (ii == ns - 1) {
    cout << "No" << endl;
    return 0;
  }

  i64 k = 0;
  bool ok = true;
  for (i64 i = ii; i < ns; i += crt) {
    if (k == sz(t)) {
      ok = false;
    }

    if (s[i] == t[k]) {
      if (ok) {
        k++;
      }
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}