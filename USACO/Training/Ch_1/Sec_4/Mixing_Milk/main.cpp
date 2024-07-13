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
TASK: milk
LANG: C++
*/

i64 min_ign(i64 a, i64 b) {
  if (a == -1) {
    return b;
  }
  if (b == -1) {
    return a;
  }

  return min(a, b);
}

i64 slv(i64 m, vp64 &cost) {
  if (m == 0) {
    return 0;
  }

  i64 ans = -1;

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("milk.in");
  ofstream cout("milk.out");

  i64 m, c;
  cin >> m >> c;

  vp64 cost(c);
  for (auto &x : cost) {
    cin >> x.ft >> x.sd;
  }

  srt(cost);

  return 0;
}