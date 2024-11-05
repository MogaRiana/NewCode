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

int f(i64 k, vi64 &v) {
  priority_queue<i64, vector<i64>, greater<i64>> q;
  for (i64 x = 0; x < k; x++) {
    q.push(v[x]);
  }

  i64 res = 0, kk = k;

  while (sz(q) == kk) {
    res += q.top();

    q.pop();

    if (k < sz(v)) {
      q.push(v[k]);
      k++;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("cowdance.in");
  ofstream cout("cowdance.out");

  i64 n, t;
  cin >> n >> t;

  vi64 v(n);
  for (auto &x : v) {
    cin >> x;
  }

  i64 k = n;
  i64 l = 1, r = n;
  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    if (f(mid, v) <= t) {
      k = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << k << endl;

  return 0;
}