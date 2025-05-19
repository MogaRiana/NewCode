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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;

  vv d(m);
  vv ind(n);
  vi64 f(m);
  for (int i = 0; i < m; i++) {
    i64 k;
    cin >> k;
    f[i] = k;
    d[i].resize(k);

    for (auto &c : d[i]) {
      cin >> c;
      c--;
      ind[c].push_back(i);
    }
  }

  i64 cnt = 0;
  while (n--) {
    i64 x;
    cin >> x;
    x--;

    for (auto &c : ind[x]) {
      f[c]--;
      if (f[c] == 0) {
        cnt++;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}