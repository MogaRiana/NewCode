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

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vp64 v(n + 1, {0, 0});
    set<i64> a;

    i64 k = 1;
    for (int i = 1; i <= n; i++) {
      cin >> v[i].ft;
      if (!a.count(v[i].ft)) {
        a.insert(v[i].ft);
        v[i].sd = k;
        k++;
      }
    }

    i64 cnt = 0;
    for (i64 i = n; i > 0; i--) {
    }

    cout << cnt << endl;
  }

  return 0;
}