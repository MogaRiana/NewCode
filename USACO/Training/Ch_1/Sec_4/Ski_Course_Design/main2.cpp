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
TASK: skidesign
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("skidesign.in");
  ofstream cout("skidesign.out");

  i64 n;
  cin >> n;

  vi64 h(n);
  for (auto &i : h) {
    cin >> i;
  }

  srt(h);
  i64 cost = 1e9;

  for (i64 i = 0; i <= 83; i++) {
    i64 m = i + 17;
    i64 tot = 0;

    for (auto &hi : h) {
      if (hi < i) {
        tot += (hi - i) * (hi - i);
      } else if (hi > m) {
        tot += (hi - m) * (hi - m);
      }
    }

    cost = min(cost, tot);
  }

  cout << cost << endl;

  return 0;
}