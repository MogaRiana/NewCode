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
typedef vec<vi32> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"omogene.in"};
  ofstream cout{"omogene.out"};

  int l, c;
  cin >> l >> c;

  int a[l][c];
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }

  vv p0(l + 1, vi32(c + 1, 0));
  vv p1(l + 1, vi32(c + 1, 0));
  vv p2(l + 1, vi32(c + 1, 0));

  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= c; j++) {
      p0[i][j] = p0[i - 1][j] + p0[i][j - 1] - p0[i - 1][j - 1] +
                 (a[i - 1][j - 1] == 0);
      p1[i][j] = p1[i - 1][j] + p1[i][j - 1] - p1[i - 1][j - 1] +
                 (a[i - 1][j - 1] == 1);
      p2[i][j] = p2[i - 1][j] + p2[i][j - 1] - p2[i - 1][j - 1] +
                 (a[i - 1][j - 1] == 2);
    }
  }

  i64 res = 0;
  for (int u = 1; u <= l; u++) {
    map<p64, i64> m;
    for (int d = u; d <= l; d++) {
      m[{0, 0}] = 1;
      i64 c0 = 0, c1 = 0, c2 = 0;

      for (i64 i = 1; i <= c; i++) {
        c0 = p0[d][i] - p0[u - 1][i];
        c1 = p1[d][i] - p1[u - 1][i];
        c2 = p2[d][i] - p2[u - 1][i];

        i64 d1 = c0 - c1;
        i64 d2 = c0 - c2;

        if (m.count({d1, d2})) {
          res += m[{d1, d2}];
        }

        m[{d1, d2}]++;
      }
      m.clear();
    }
  }

  cout << res << endl;

  return 0;
}