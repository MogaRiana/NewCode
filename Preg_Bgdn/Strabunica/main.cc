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

const int NMAX = 200005;
i64 l[NMAX], r[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"strabunica.in"};
  ofstream cout{"strabunica.out"};

  int n;
  cin >> n;

  vi64 v(n);
  for (auto &i : v) {
    cin >> i;
  }

  vi64 s;
  i64 res = 0;

  for (int i = 0; i < n; i++) {
    while (sz(s) > 0 && v[s.back()] >= v[i]) {
      s.pop_back();
    }
    if (sz(s) > 0) {
      l[i] = s.back();
    } else {
      l[i] = 0;
    }
    s.push_back(i);
  }

  s.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (sz(s) > 0 && v[s.back()] >= v[i]) {
      s.pop_back();
    }
    if (sz(s) > 0) {
      r[i] = s.back();
    } else {
      r[i] = n;
    }
    s.push_back(i);
  }

  for (int i = 0; i < n; i++) {
    res = max(res, v[i] * (r[i] - l[i] - 1));
  }

  cout << res << endl;

  return 0;
}