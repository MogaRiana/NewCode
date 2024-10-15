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

  ifstream cin("qtsume.in");
  ofstream cout("qtsume.out");

  i64 n;
  cin >> n;

  vi64 v(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> v[i];
  }

  vi64 s1(n + 1);
  s1[0] = 0;
  s1[1] = v[1];
  for (i64 i = 2; i <= n; i++) {
    s1[i] = s1[i - 1] + v[i];
  }

  vi64 s2(n + 1);
  s2[0] = 0;
  s2[1] = v[1];
  for (i64 i = 2; i <= n; i++) {
    s2[i] = s2[i - 1] + i * v[i];
  }

  i64 q;
  cin >> q;

  while (q--) {
    i64 x, y;
    cin >> x >> y;

    cout << s2[y] - s2[x - 1] - (x - 1) * (s1[y] - s1[x - 1]) << endl;
  }

  return 0;
}