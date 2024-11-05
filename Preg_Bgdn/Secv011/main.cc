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

const i64 N = 1e6;
int n, f[4 * N + 3], x, p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"secv011.in"};
  ofstream cout{"secv011.out"};

  cin >> n;

  i64 res = 0;
  i64 p = 0;

  f[2 * N] = 1;
  for (int i = 1; i <= n; i++) {
    i64 x;
    cin >> x;

    if (x == 0) {
      p -= 2;
    } else {
      p += 1;
    }

    res += f[2 * N + p];
    f[2 * N + p]++;
  }

  cout << res << endl;

  return 0;
}