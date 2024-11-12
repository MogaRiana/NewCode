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
typedef pair<i32, i32> p32;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

int l, c;
int pref[301][301], a[301][301];
void pp() {
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= c; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   a[i - 1][j - 1];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"matd3.in"};
  ofstream cout{"matd3.out"};

  cin >> l >> c;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      a[i][j] = a[i][j] % 3;
    }
  }

  pp();

  i64 res = 0;
  for (int col = 1; col <= c; col++) {
    for (int j = col; j <= c; j++) {
      vector<int> m(3, 0);
      m[0] = 1;
      for (int i = 1; i <= l; i++) {
        i64 sum = (pref[i][j] - pref[i][col - 1]) % 3;

        if (m[sum] != 0) {
          res += m[sum];
        }

        m[sum]++;
      }
    }
  }

  cout << res << endl;

  return 0;
}