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
  i64 tot = 0;
  for (auto &x : cost) {
    if (m == 0) {
      break;
    }

    if (x.sd <= m) {
      i64 d = m - x.sd;
      tot += x.ft * x.sd;
      m -= x.sd;
    } else {
      tot += m * x.ft;
      m = 0;
    }
  }

  cout << tot << endl;

  return 0;
}