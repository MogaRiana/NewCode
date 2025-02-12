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

// const int NMAX = 100002;
// int a[NMAX][NMAX];

bool ver(vv &a, int l1, int c1, int l2, int c2) {
  for (int i = l1; i <= l2; ++i) {
    if (a[i][c1] != 1 || a[i][c2] != 1)
      return false;
  }
  for (int j = c1; j <= c2; ++j) {
    if (a[l1][j] != 1 || a[l2][j] != 1)
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"chenare.in"};
  ofstream cout{"chenare.out"};

  int n, m;
  cin >> n >> m;
  vv a(n, vi64(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        for (int k = i; k < n; k++) {
          for (int l = j; l < m; l++) {
            if (a[k][l] and ver(a, i, j, k, l)) {
              ans = max(ans, (k - i + 1) * (l - j + 1));
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}