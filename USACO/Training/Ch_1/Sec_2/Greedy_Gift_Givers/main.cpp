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
TASK: gift1
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("gift1.in");
  ofstream cout("gift1.out");

  i64 n;
  cin >> n;

  vec<str> nn(n);
  unordered_map<str, i64> list;
  for (i64 i = 0; i < n; i++) {
    cin >> nn[i];
    list[nn[i]] = 0;
  }

  str name;
  i64 mon, nr;
  while (cin >> name >> mon >> nr) {
    if (nr == 0) {
      continue;
    }

    i64 d = mon / nr;
    list[name] -= mon;
    list[name] += mon % nr;

    while (nr--) {
      str fr;
      cin >> fr;
      list[fr] += d;
    }
  }

  for (i64 i = 0; i < n; i++) {
    cout << nn[i] << " " << list[nn[i]] << endl;
  }

  return 0;
}