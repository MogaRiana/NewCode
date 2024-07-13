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

i64 dist(i64 x1, i64 y1, i64 x2, i64 y2) {
  i64 d1 = x1 - x2;
  i64 d2 = y1 - y2;

  return (d1 * d1 + d2 * d2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  i64 ab = dist(xa, ya, xb, yb);
  i64 bc = dist(xb, yb, xc, yc);
  i64 ca = dist(xc, yc, xa, ya);

  if (ab + bc == ca || bc + ca == ab || ca + ab == bc) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}