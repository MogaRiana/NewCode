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

i64 n, a, b;
vi64 v;

i64 f(i64 m) {
  i64 ans = 0;
  i64 j = n;
  for (int i = 1; i <= n; i++) {
    while (j > 0 && v[j - 1] * v[i - 1] >= m) {
      j--;
    }
    ans += j;
  }
  return ans;
}

i64 slv(i64 val) {
  i64 st = 1, dr = LONG_LONG_MAX, mid = 0, sol = 0;

  while (st <= dr) {
    mid = st + (dr - st) / 2;

    if (f(mid) >= val) {
      sol = mid;
      dr = mid - 1;
    } else {

      st = mid + 1;
    }
  }

  return sol;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"dif2.in"};
  ofstream cout{"dif2.out"};

  int c;
  cin >> c >> n;
  v.resize(n);

  if (c == 1) {
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      v[i] = v[i] * v[i];
    }

    rsrt(v);
    cout << v[0] - v[n - 1] << endl;
  } else if (c == 2) {
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    srt(v);
    cout << abs(slv(a) - slv(b)) << endl;
  }

  return 0;
}