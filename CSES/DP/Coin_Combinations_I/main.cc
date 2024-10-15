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

int n, k;
int coin[102];
int dp[1000004];
const int MOD = 1e9 + 7;

void slv() {
  dp[0] = 1;

  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      if (i - coin[j] >= 0) {
        dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
      }
    }
  }
}

/*
2 1
3 1
4 1
5 3
6 2
7 5
8 6
9 8

*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (i64 i = 0; i < n; i++) {
    cin >> coin[i];
  }

  slv();
  cout << dp[k] << endl;

  return 0;
}