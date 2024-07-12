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

/*
ID: Riana Moga (rianamo1)
TASK: barn1
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("barn1.in");
  ofstream cout("barn1.out");

  i64 m, s, c;
  cin >> m >> s >> c;

  vi64 pos(c);
  for (i64 i = 0; i < c; i++) {
    cin >> pos[i];
  }

  srt(pos);

  vi64 dif;
  for (i64 i = 0; i < c - 1; i++) {
    dif.push_back(pos[i + 1] - pos[i] - 1);
  }

  rsrt(dif);
  i64 sum = pos[c - 1] - pos[0] + 1;

  for (i64 i = 0; i < sz(dif) and i < m - 1; i++) {
    sum -= dif[i];
  }

  cout << sum << endl;

  return 0;
}