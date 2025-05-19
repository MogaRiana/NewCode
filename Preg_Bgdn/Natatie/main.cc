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

int n, m;
bool f(long double t, vp64 &rate, vi64 &b) {
  int j = 0;

  for (int i = 0; i < n; i++) {
    if (1.0 * rate[i].sd * t >= 2.0 * b[j]) {
      j++;
    }
    if (j == m) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"natatie.in"};
  ofstream cout{"natatie.out"};

  cin >> n >> m;

  vp64 rate(n);
  for (int i = 0; i < n; i++) {
    cin >> rate[i].sd;
  }
  for (int i = 0; i < n; i++) {
    cin >> rate[i].ft;
  }

  srt(rate);
  vi64 balize(m);
  for (int i = 0; i < m; i++) {
    cin >> balize[i];
  }

  i64 l = 0, r = 2 * 1e12;
  long double res = 0;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    long double t = (long double)mid / 1000;
    if (f(t, rate, balize)) {
      res = t;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << fixed << setprecision(3) << res << endl;

  return 0;
}