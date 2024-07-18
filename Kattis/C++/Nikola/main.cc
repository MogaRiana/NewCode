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

vector<int> v;
using ll = long long;
const ll INF = 1e18;
int n;

ll dp[1024][1024];

ll solve(int i, int p) {
  if (i >= n || i < 0) {
    return INF;
  }
  if (i == n - 1) {
    return v[i];
  }
  if (dp[i][p] != 0) {
    return dp[i][p];
  }

  return dp[i][p] = v[i] + min(solve(i + p + 1, p + 1), solve(i - p, p));
}

int main() {
  int x;
  cin >> n;

  for (int i = 0; i < n; i += 1) {
    cin >> x;
    v.push_back(x);
  }

  cout << solve(1, 1) << endl;
  return 0;
}