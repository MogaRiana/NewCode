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

auto fsort = [](const pair<p64, i64> &a, const pair<p64, i64> &b) {
  if (a.ft.first != b.ft.first)
    return a.ft.first < b.ft.first;
  return a.ft.second > b.ft.second;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  vec<pair<p64, i64>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].ft.ft >> v[i].ft.sd;
    v[i].sd = i;
  }

  sort(v.begin(), v.end(), fsort);

  vi64 res(n, 0);
  i64 k = 1e9 + 7;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i].ft.sd >= k) {
      res[v[i].sd] = 1;
    }

    k = min(k, v[i].ft.sd);
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
    res[i] = 0;
  }

  k = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].ft.sd <= k) {
      res[v[i].sd] = 1;
    }

    k = max(k, v[i].ft.sd);
  }

  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }

  return 0;
}