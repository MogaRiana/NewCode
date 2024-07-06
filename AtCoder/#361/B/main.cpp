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

bool ver(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j,
         int k, int l) {
  bool x_overlap = max(a, g) < min(d, j);
  bool y_overlap = max(b, h) < min(e, k);
  bool z_overlap = max(c, i) < min(f, l);

  return x_overlap && y_overlap && z_overlap;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 a, b, c, d, e, f;
  i64 a1, b1, c1, d1, e1, f1;

  cin >> a >> b >> c >> d >> e >> f;
  cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;

  if (ver(a, b, c, d, e, f, a1, b1, c1, d1, e1, f1)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}