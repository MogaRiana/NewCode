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

void solve(vi32 &h, i32 &cost) {
  i32 n = sz(h);
  srt(h);

  if (h[n - 1] - h[0] <= 17) {
    return;
  }

  i32 x = (h[n - 1] - h[0] - 17);
  if (x % 2 != 0) {
    x = x / 2 + 1;
  } else {
    x = x / 2;
  }

  cost += 2 * x * x;
  h[n - 1] -= x;
  h[0] += x;

  solve(h, cost);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // 22946
  ifstream cin("skidesign.in");
  ofstream cout("skidesign.out");

  i32 n;
  cin >> n;

  vi32 h(n);
  for (auto &i : h) {
    cin >> i;
  }

  srt(h);

  i32 cost = 0;
  solve(h, cost);

  cout << cost << endl;

  return 0;
}