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
TASK: combo
LANG: C++
*/

void init(map<i64, i64> &m, vi64 &v, i64 n, i64 i) {
  i64 ii = v[i];

  m[ii]++;

  if (ii == 1) {
    m[2]++;
    m[3]++;
    m[n]++;
    m[n - 1]++;
  } else if (ii == 2) {
    m[1]++;
    m[3]++;
    m[4]++;
    m[n]++;
  } else if (ii == n) {
    m[n - 2]++;
    m[n - 1]++;
    m[1]++;
    m[2]++;
  } else if (ii == n - 1) {
    m[n - 3]++;
    m[n - 2]++;
    m[n]++;
    m[1]++;
  } else {
    m[ii + 1]++;
    m[ii + 2]++;
    m[ii - 1]++;
    m[ii - 2]++;
  }
}

i64 cnt(map<i64, i64> m) {
  i64 crt = 0;
  for (auto &[k, v] : m) {
    if (v > 1) {
      crt++;
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("combo.in");
  ofstream cout("combo.out");

  i64 n;
  cin >> n;

  vi64 j(3);
  vi64 m(3);
  cin >> j[0] >> j[1] >> j[2];
  cin >> m[0] >> m[1] >> m[2];

  if (n <= 5) {
    cout << pow(n, 3) << endl;
    return 0;
  }

  map<i64, i64> a, b, c;

  init(a, j, n, 0);
  init(a, m, n, 0);
  init(b, j, n, 1);
  init(b, m, n, 1);
  init(c, j, n, 2);
  init(c, m, n, 2);

  i64 crta = cnt(a), crtb = cnt(b), crtc = cnt(c);

  cout << 250 - (crta * crtb * crtc) << endl;

  return 0;
}