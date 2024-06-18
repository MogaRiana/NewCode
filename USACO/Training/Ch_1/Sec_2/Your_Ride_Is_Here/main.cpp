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
TASK: ride
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("ride.in");
  ofstream cout("ride.out");

  str s, ss;
  cin >> s >> ss;

  i64 s1 = 1, s2 = 1;
  for (i64 i = 0; i < sz(s); i++) {
    s1 *= (s[i] - 'A' + 1);
  }
  for (i64 i = 0; i < sz(ss); i++) {
    s2 *= (ss[i] - 'A' + 1);
  }

  if (s1 % 47 == s2 % 47) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }

  return 0;
}