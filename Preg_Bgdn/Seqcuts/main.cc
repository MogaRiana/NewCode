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

// char ans[2000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, l;
  cin >> n >> k >> l;

  str s;
  cin >> s;

  char ans[n + 1];
  fill(ans, ans + n + 1, 0);

  int m = 0;
  for (int i = 0; i < n; i++) {
    while (m >= l and k > 0 and ans[m - l] >= s[i]) {
      k--;
      m -= l;
    }

    ans[m++] = s[i];
  }

  cout << ans << endl;

  return 0;
}