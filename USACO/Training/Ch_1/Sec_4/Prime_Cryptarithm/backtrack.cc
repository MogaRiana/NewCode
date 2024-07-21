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
TASK: crypt1
LANG: C++
*/

set<i64> d;
bool ver(i64 n) {
  while (n) {
    if (!d.count(n % 10)) {
      return false;
    }
    n /= 10;
  }
  return true;
}

vi64 res1, res2;
void sol(int n, int pos, int nr) {
  if (pos == n) {
    if (n == 3) {
      res1.push_back(nr);
    } else if (n == 2) {
      res2.push_back(nr);
    }
    return;
  }

  for (auto &i : d) {
    sol(n, pos + 1, nr * 10 + i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("crypt1.in");
  ofstream cout("crypt1.out");

  i64 n;
  cin >> n;

  for (i64 i = 0; i < n; i++) {
    i64 k;
    cin >> k;

    d.insert(k);
  }

  sol(3, 0, 0);
  sol(2, 0, 0);

  i64 ans = 0;
  for (auto &i : res1) {
    for (auto &j : res2) {
      i64 a = i * (j % 10);
      i64 b = i * (j / 10);
      i64 c = i * j;

      if (ver(a) and ver(b) and ver(c) and (a >= 100 and a <= 999) and
          (b >= 100 and b <= 999) and (c >= 1000 and c <= 9999)) {
        // cout << i << " " << j << endl;
        // cout << a << " " << b << " " << c << endl;
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}