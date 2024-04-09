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

i64 fib(i64 id, i64 v1, i64 v2, i64 k, vi64 &v) {
  i64 crt = v1 + v2;
  if (v[crt % k] != 0) {
    return v[crt % k];
  }

  v[crt % k] = id;
  return fib(id + 1, v2 % k, crt % k, k, v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 k;
    cin >> k;

    vi64 v(k);
    v[0] = 0;
    cout << fib(2, 1, 1, k, v) << endl;
  }

  return 0;
}