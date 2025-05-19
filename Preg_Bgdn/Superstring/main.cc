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

int cif(i64 x) {
  i64 cnt = 0;
  while (x) {
    x /= 10;
    cnt++;
  }

  return cnt;
}

int gauss(int n) { return (1 + n) * n / 2; }

int g(i64 t) {
  i64 p1 = pow(10, t);
  i64 p2 = pow(10, t - 1);
  return t * (gauss(p1 - 1) - gauss(p2 - 1));
}

int f(i64 k) {
  int c = cif(k);
  i64 sum = 0;
  for (int i = 1; i < c; i++) {
    sum += g(i);
  }

  i64 p = pow(10, c - 1);
  sum += (gauss(k) - gauss(p - 1)) * c;

  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"superstring.in"};
  ofstream cout{"superstring.out"};

  int q;
  cin >> q;

  while (q--) {
    i64 k;
    cin >> k;

    i64 l = 0, r = k;
    i64 res = 0;
    while (l <= r) {
      i64 mid = l + (r - l) / 2;
      if (f(mid) >= k) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    k -= f(res - 1);
    i64 c = cif(res);

    k %= c;
    if (!k) {
      k = c;
    }

    res /= pow(10, c - k);
    cout << res % 10 << endl;
  }

  return 0;
}