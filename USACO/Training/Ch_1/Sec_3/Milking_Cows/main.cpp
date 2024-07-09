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
TASK: milk2
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin("milk2.in");
  // ofstream cout("milk2.out");

  i64 n;
  cin >> n;

  vp64 farmers(n);
  for (auto &p : farmers) {
    cin >> p.ft >> p.sd;
  }

  srt(farmers);
  i64 start = farmers[0].ft, end = farmers[0].sd;
  i64 rr1 = 0, rr2 = 0;

  for (i64 i = 0; i < n; i++) {
    if (farmers[i].ft > end) {
      rr1 = max(rr1, end - start);
      rr2 = max(rr2, farmers[i].ft - end);

      start = farmers[i].ft;
      end = farmers[i].sd;
    } else if (farmers[i].sd > end) {
      end = farmers[i].sd;
    }
  }

  rr1 = max(rr1, end - start);

  if (n > 1) {
    cout << rr1 << " " << rr2 << endl;
  } else {
    cout << farmers[0].sd - farmers[0].ft << " " << 0 << endl;
  }

  return 0;
}