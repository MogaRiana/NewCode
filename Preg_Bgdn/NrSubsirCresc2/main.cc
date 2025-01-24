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

const int NMAX = 402;
i64 dp[NMAX][NMAX];
int a[NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"nrsubsircresc2.in"};
  ofstream cout{"nrsubsircresc2.out"};

  int n, p;
  cin >> n >> p;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][1] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int k = 2; k <= p; k++) {
      for (int j = i - 1; j > 0; j--) {
        if (a[i] > a[j]) {
          dp[i][k] += dp[j][k - 1];
        }
      }
    }
  }

  i64 sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += dp[i][p];
  }

  cout << sum << endl;

  return 0;
}