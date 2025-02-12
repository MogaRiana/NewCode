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

const int NMAX = 100002;
int a[NMAX];
int dp[4 * NMAX];

void update(int n, int l, int r, int p, int val) {
  if (l == r) {
    dp[n] = max(val, dp[n]);
    return;
  }

  int mid = (l + r) / 2;

  if (p <= mid) {
    update(n * 2, l, mid, p, val);
  } else {
    update(n * 2 + 1, mid + 1, r, p, val);
  }

  dp[n] = max(dp[2 * n], dp[2 * n + 1]);
}

void query(int n, int l, int r, int x, int y, int &rr) {
  if (x <= l and r <= y) {
    rr = max(rr, dp[n]);
    return;
  }

  int mid = (l + r) / 2;

  if (x <= mid) {
    query(n * 2, l, mid, x, y, rr);
  }
  if (mid < y) {
    query(n * 2 + 1, mid + 1, r, x, y, rr);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  update(1, 1, n, a[0], 1);

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] - 1 == 0) {
      continue;
    }

    int rr = 0;
    query(1, 1, n, 1, a[i] - 1, rr);
    rr++;
    update(1, 1, n, a[i], rr);

    res = max(res, rr);
  }

  cout << n - res << endl;

  return 0;
}