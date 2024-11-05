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

i32 n;
vi32 v;

i32 cnt(i32 x, i32 y) {
  i32 ans = 0;

  i32 px = 0, mx = 0;
  i32 py = 0, my = 0;

  for (i32 i = 0; i < n; i++) {
    if (v[i] == y) {
      py = i + 1;
    }
    if (v[i] == x) {
      px = i + 1;
    }

    if (v[i] > y) {
      my = i + 1;
    }
    if (v[i] < x) {
      mx = i + 1;
    }

    if (my < py) {
      ans += py - my;
    }
    if (mx < px) {
      ans += px - my;
    }
  }

  i32 k = 0;
  for (i32 i = 0; i < n; i++) {
    if (v[i] <= y and v[i] >= x) {
      k++;
    } else {
      k = 0;
    }

    ans += k;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 x, y;
  cin >> n >> x >> y;

  v.resize(n);
  for (auto &i : v) {
    cin >> i;
  }

  cout << cnt(x, y) - cnt(x, y - 1) - cnt(x + 1, y) + cnt(x + 1, y - 1) << endl;

  return 0;
}