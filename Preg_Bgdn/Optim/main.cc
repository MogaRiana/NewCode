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

const int NMAX = 31;

int dpmax[NMAX][NMAX];
int dpmin[NMAX][NMAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"optim.in"};
  ofstream cout{"optim.out"};

  int n, k;
  cin >> n >> k;

  vi32 v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    dpmax[i][0] = dpmax[i - 1][0] + v[i];
    dpmin[i][0] = dpmin[i - 1][0] + v[i];
  }

  for (int i = 1; i <= n; i++) {
    int summin = 1;
    for (int j = 1; j <= min(i - 1, k); j++) {
      if (j == i - 1) {
        summin = 1;
        for (int l = 1; l <= i; l++) {
          summin *= v[l];
        }

        dpmin[i][j] = summin;
      } else {
        dpmin[i][j] = dpmin[i - 1][j] + v[i];
        summin = v[i];

        for (int l = 1; l <= j; l++) {
          summin *= v[i - l];
          dpmin[i][j] = min(dpmin[i - l - 1][j - l] + summin, dpmin[i][j]);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int summax = 1;
    for (int j = 1; j <= min(i - 1, k); j++) {
      if (j == i - 1) {
        summax = 1;
        for (int l = 1; l <= i; l++) {
          summax *= v[l];
        }

        dpmax[i][j] = summax;
      } else {
        dpmax[i][j] = dpmax[i - 1][j] + v[i];
        summax = v[i];

        for (int l = 1; l <= j; l++) {
          summax *= v[i - l];
          dpmax[i][j] = max(dpmax[i - l - 1][j - l] + summax, dpmax[i][j]);
        }
      }
    }
  }

  cout << dpmin[n][k] << " " << dpmax[n][k] << endl;

  return 0;
}