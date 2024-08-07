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

  i64 n, x, y;
  cin >> n >> x >> y;

  vi64 sweet(n), salt(n);
  for (i64 i = 0; i < n; i++) {
    cin >> sweet[i];
  }
  for (i64 i = 0; i < n; i++) {
    cin >> salt[i];
  }

  rsrt(sweet);
  rsrt(salt);

  i64 crtx = 0, crty = 0;
  i64 sumx = 0, sumy = 0;
  for (i64 i = 0; i < n; i++) {
    crtx++;
    sumx += sweet[i];

    if (sumx > x) {
      break;
    }
  }

  for (i64 i = 0; i < n; i++) {
    crty++;
    sumy += salt[i];

    if (sumy > y) {
      break;
    }
  }

  cout << min(crtx, crty) << endl;

  return 0;
}