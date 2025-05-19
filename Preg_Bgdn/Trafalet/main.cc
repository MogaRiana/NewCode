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

int n, m;
i64 mat[502][502];
i64 mat2[502][502];

i64 pref1[502][502];
i64 pref2[502][502];

i64 calc() {
  i64 res = -1e9, res2 = -1e9;

  for (int u = 1; u <= n; u++) {
    for (int d = u; d <= n; d++) {
      i64 st = 0, st2 = 0;
      for (int i = 1; i <= m; i++) {
        i64 sum = pref1[d][i] - pref1[u - 1][i];
        i64 sum2 = pref2[d][i] - pref2[u - 1][i];

        st = min(st, sum);
        st2 = min(st2, sum2);

        res = max(res, sum - st);
        res2 = max(res2, sum2 - st2);
      }
    }
  }

  cout << res << " " << res2 << endl;
  return max(res, res2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"trafalet.in"};
  ofstream cout{"trafalet.out"};

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mat[i][j];
      mat2[i][j] = mat[i][j];

      if ((i + j) % 2 == 0) {
        mat[i][j] *= -1;
      } else {
        mat2[i][j] *= -1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref1[i][j] =
          pref1[i - 1][j] + pref1[i][j - 1] - pref1[i - 1][j - 1] + mat[i][j];

      pref2[i][j] =
          pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1] + mat2[i][j];
    }
  }

  cout << calc() << endl;

  return 0;
}