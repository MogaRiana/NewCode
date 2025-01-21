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
bool rr[NMAX];
int dp[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"sclm.in"};
  ofstream cout{"sclm.out"};

  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int res = 0, p = -1;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = i; j >= 0; j--) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }

    if (dp[i] > res) {

      res = dp[i];
      p = i;
    }
  }

  int x = res;
  rr[p] = true;
  for (int i = p - 1; i >= 0; i--) {
    if (dp[i] == x - 1) {
      rr[i] = true;
      x--;
    }
  }

  cout << res << endl;
  for (int i = 0; i < n; i++) {
    if (rr[i]) {
      cout << i + 1 << " ";
    }
  }

  return 0;
}