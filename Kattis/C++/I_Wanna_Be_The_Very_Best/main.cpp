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

void ins(map<i64, i64> &v, set<i64> &res, i64 k) {
  i64 cnt = 0;
  for (auto it = v.rbegin(); it != v.rend(); it++) {
    if (cnt < k) {
      cnt++;
      res.insert(it->sd);
    } else {
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;

  map<i64, i64> a;
  map<i64, i64> d;
  map<i64, i64> h;

  for (i64 i = 0; i < n; i++) {
    i64 at, df, he;
    cin >> at >> df >> he;

    a[at] = i;
    d[df] = i;
    h[he] = i;
  }

  set<i64> res;
  ins(a, res, k);
  ins(d, res, k);
  ins(h, res, k);

  cout << res.size() << endl;

  return 0;
}