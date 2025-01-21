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

const int NMAX = 1002;
i64 dp[NMAX][NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"subsircomunmaximal.in"};
  ofstream cout{"subsircomunmaximal.out"};

  str a, b;
  cin >> a >> b;

  for (int i = 0; i < sz(b); i++) {
    for (int j = 0; j < sz(a); j++) {
      if (b[i] == a[j]) {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  str res = "";
  int i = sz(b), j = sz(a);
  while (i > 0 and j > 0) {
    if (b[i - 1] == a[j - 1]) {
      res += b[i - 1];
      i--;
      j--;
      continue;
    }
    if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  rvs(res);
  cout << res << endl;

  return 0;
}