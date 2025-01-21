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

const int NM = 100, MM = 100;
int a[NM][MM];

void pref(int n, int m) {
  for (i64 i = 1; i < n; i++) {
    a[i][0] += a[i - 1][0];
  }
  for (i64 j = 1; j < m; j++) {
    a[0][j] += a[0][j - 1];
  }

  for (i64 i = 1; i < n; i++) {
    for (i64 j = 1; j < m; j++) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"investitie.in"};
  ofstream cout{"investitie.out"};

  int c, l;
  cin >> c >> l;

  int s[c];

  for (int i = 0; i < c; i++) {
    cin >> a[1][i];
    s[i] = a[1][i];
  }

  for (int i = 1; i < l; i++) {
    for (int j = 0; j < c; j++) {
      a[i][j] += a[i - 1][s[j]];
    }
  }

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  pref(l, c);

  int q;
  cin >> q;

  while (q--) {
    int res = 0;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    if (x1 && x2 && y1 && y2) {
      res = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
    } else if (x1 == 0 && y1 == 0) {
      res = a[x2][y2];
    } else if (y1 == 0) {
      res = a[x2][y2] - a[x1 - 1][y2];
    } else if (x1 == 0) {
      res = a[x2][y2] - a[x2][y1 - 1];
    }

    cout << res << endl;
  }

  return 0;
}