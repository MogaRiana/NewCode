#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
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

class fentree {
private:
  vi64 ft;

public:
  fentree(i64 m) { ft.assign(m + 1, 0); }
  void update(i64 pos, i64 val = 1) {
    i64 crt = pos + 1;
    while (crt < ft.size()) {
      ft[crt] += val;
      crt += LSOne(crt);
    }
  }

  i64 rsq(i64 pos) {
    i64 crt = pos + 1;
    i64 ans = 0;
    while (crt > 0) {
      ans += ft[crt];
      crt -= LSOne(crt);
    }
    return ans;
  }

  i64 rsq(i64 l, i64 r) { return rsq(r) - rsq(l - 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vi64 v(n), l(n, 0), r(n, 0);
  for (auto &i : v) {
    cin >> i;
  }

  fentree fl(n + 2), fr(n + 2);
  for (i64 i = 0; i < n; i++) {
    l[i] = fl.rsq(v[i] + 1, n);
    fl.update(v[i]);
  }
  for (i64 i = n - 1; i >= 0; i--) {
    r[i] = fr.rsq(v[i] - 1);
    fr.update(v[i]);
  }

  i64 sol = 0;
  for (i64 i = 0; i < n; i++) {
    sol += l[i] * r[i];
  }

  cout << sol << endl;

  return 0;
}