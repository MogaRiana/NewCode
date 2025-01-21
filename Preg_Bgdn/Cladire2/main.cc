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

const int NMAX = 202;
i64 dp[NMAX][NMAX];
int a[NMAX][NMAX];
int x[NMAX];
int y[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"cladire2.in"};
  ofstream cout{"cladire2.out"};

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  x[1] = n;
  y[1] = m;

  int i = n, j = m, k = 1;
  while (i != 1 or j != 1) {
    int c = dp[i][j] - a[i][j];
    if (c == dp[i - 1][j]) {
      i--;
    } else {
      j--;
    }

    k++;
    x[k] = i;
    y[k] = j;
  }

  cout << dp[n][m] << endl;
  for (int i = n + m - 1; i > 0; i--) {
    cout << x[i] << " " << y[i] << endl;
  }

  return 0;
}