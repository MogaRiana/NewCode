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

i64 a1, a2, b1, b2;

void cnt(i64 a, i64 b1, i64 b2, i64 &crt) {
  if (a > b1) {
    crt++;
  }
  if (a > b2) {
    crt++;
  }
}

// true 1 1 false 0 2
bool ver() {
  i64 c = 0;
  if (a1 > b1) {
    c++;
  }
  if (a1 > b2) {
    c++;
  }

  if (c == 1) {
    return true;
  }

  return false;
}

/*
  a1 > b1 and a1 < b2 and a2 > b1 and a2 < b2
  b1 a1 b2    b1 a2 b2

  a1 > b2 and a1 < b1 and a2 > b2 and a2 < b1
  b2 a1 b1    b2 a2 b1
*/

void solve() {
  cin >> a1 >> a2 >> b1 >> b2;

  i64 crt = 0;
  cnt(a1, b1, b2, crt);
  cnt(a2, b1, b2, crt);

  if (crt == 4) {
    cout << 4 << endl;
  } else if (crt == 3) {
    cout << 2 << endl;
  } else {
    cout << 0 << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}