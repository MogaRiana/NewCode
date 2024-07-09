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
TASK: friday
LANG: C++
*/

bool isLeapYear(int year) {
  if (year % 100 == 0)
    return year % 400 == 0;
  return year % 4 == 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("friday.in");
  ofstream cout("friday.out");

  vi64 days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vi64 week = {0, 0, 0, 0, 0, 0, 0};

  i64 n;
  cin >> n;

  i64 fd = 1;
  for (i64 i = 1900; i < 1900 + n; i++) {
    bool leap = isLeapYear(i);

    i64 x = leap ? 365 : 366;
    days[1] = leap ? 29 : 28;

    for (i64 m = 0; m < 12; m++) {
      i64 xx = (6 + fd - 1) % 7;
      week[xx]++;

      fd = (days[m] % 7 + fd) % 7;
    }
  }

  cout << week[6] << " " << week[0];
  for (i64 i = 1; i < 6; i++) {
    cout << " " << week[i];
  }
  cout << endl;

  return 0;
}