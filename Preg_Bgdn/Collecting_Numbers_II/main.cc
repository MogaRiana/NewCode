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

i64 n, q;
vi64 ind(0);
set<p64> s;
i64 res() {
  i64 cnt = 0;
  for (auto &x : s) {
    if (ind[x.ft] > ind[x.sd]) {
      cnt++;
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> q;

  ind.resize(n + 1);
  vi64 v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    ind[v[i]] = i;
  }

  i64 cnt = 1;
  for (int i = 1; i < n; i++) {
    if (ind[i] > ind[i + 1]) {
      cnt++;
    }
  }

  while (q--) {
    int a, b;
    cin >> a >> b;

    if (v[a] + 1 <= n) {
      s.insert({v[a], v[a] + 1});
    }
    if (v[a] - 1 >= 1) {
      s.insert({v[a] - 1, v[a]});
    }
    if (v[b] + 1 <= n) {
      s.insert({v[b], v[b] + 1});
    }
    if (v[b] - 1 >= 1) {
      s.insert({v[b] - 1, v[b]});
    }

    cnt -= res();

    swap(v[a], v[b]);
    ind[v[a]] = a;
    ind[v[b]] = b;

    cnt += res();

    cout << cnt << endl;
    s.clear();
  }

  return 0;
}