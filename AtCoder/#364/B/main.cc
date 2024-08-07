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

  i64 l, c;
  p64 cur;

  cin >> l >> c;
  cin >> cur.ft >> cur.sd;

  cur.ft--;
  cur.sd--;

  vec<str> v(l);
  for (auto &s : v) {
    cin >> s;
  }

  str dir;
  cin >> dir;

  for (auto &d : dir) {
    if (d == 'U') {
      if (cur.ft > 0 and v[cur.ft - 1][cur.sd] == '.') {
        cur.ft--;
      }
    } else if (d == 'D') {
      if (cur.ft < l - 1 and v[cur.ft + 1][cur.sd] == '.') {
        cur.ft++;
      }
    } else if (d == 'L') {
      if (cur.sd > 0 and v[cur.ft][cur.sd - 1] == '.') {
        cur.sd--;
      }
    } else if (d == 'R') {
      if (cur.sd < c - 1 and v[cur.ft][cur.sd + 1] == '.') {
        cur.sd++;
      }
    }
  }

  cout << cur.ft + 1 << " " << cur.sd + 1 << endl;

  return 0;
}